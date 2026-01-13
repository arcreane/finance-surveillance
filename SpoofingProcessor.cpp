#include "SpoofingProcessor.h"

std::optional<Alert> SpoofingProcessor::process(const Order& order)
{
	historicOrders.push_back(order);
	while (!historicOrders.empty() && historicOrders.begin()->getTimestampCreated() < order.getTimestampCreated() - window) {
		historicOrders.erase(historicOrders.begin());
	}
	int totalLargeOrders = 0;
	int cancelLargeOrders = 0;
	for (const auto& order : historicOrders) {
		if (order.getQuantity() >= bigOrderThreshold) {
			totalLargeOrders++;
			cancelTime = order.getTimestampCreated();
			if (cancelTime <= baitTimeWindow) {

			}
			if (order.getStatus() == status::CANCELLED){}
			cancelLargeOrders++;
			suspiciousOrders.push_back(order);
		}

		if (cancelLargeOrders > 0) {
			cancelRatio = static_cast<double>(cancelLargeOrders / totalLargeOrders);
		}

		if (cancelLargeOrders >= bigOrderThreshold) {

		}
	}
	return std::nullopt;
}