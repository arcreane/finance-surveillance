#pragma once
#include "order.h"
#include "IProcessor.h"
#include <vector>

class SpoofingProcessor : public IProcessor {
public:
	SpoofingProcessor() {}
	std::optional<Alert> process(const Order& order) override;

private:
	time_t window;
	time_t detectionWindow;
	double volumeHistoric;
	double cancelRatio = 0.9; // suppose cancel rate to 0.9
	double bigOrderThreshold; // estimate the amount/number of big orders
	time_t baitTimeWindow = 1; //time limit for bait
	time_t cancelTime;
	time_t reversedBaitTimeWindow;
	std::vector<Order> suspiciousOrders;
	std::vector<Order> historicOrders;
};