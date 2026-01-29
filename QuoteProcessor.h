#pragma once
#include "order.h"
#include "IProcessor.h"
#include <vector>

//Not in use for now since really close scheme to spoofing scheme
class QuoteProcessor : public IProcessor {
public:
	std::optional<Alert> process(const Order& order) override;
private:
	time_t window;
	double volumeHistoric;
	std::vector<Order> suspiciousOrders;
	std::vector<Order> historicOrders;

};
