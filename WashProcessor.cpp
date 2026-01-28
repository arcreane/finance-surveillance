#include "WashProcessor.h"

std::optional<Alert> WashProcessor::process(const Order& order)
{
	historicOrders.push_back(order);

	while (!historicOrders.empty() && historicOrders.begin()->getTimestampCreated() < order.getTimestampCreated() - window) {
		historicOrders.erase(historicOrders.begin());
	}

	return std::nullopt;
}