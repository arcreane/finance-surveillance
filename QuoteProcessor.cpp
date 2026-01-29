#include "QuoteProcessor.h"

std::optional<Alert> QuoteProcessor::process(const Order& order)
{
    historicOrders.push_back(order);
    while (!historicOrders.empty() && historicOrders.begin()->getTimestampCreated() < order.getTimestampCreated() - window) {
        historicOrders.erase(historicOrders.begin());
    }

    int numNew = static_cast<int>(historicOrders.size());
    int numCancelled = 0;
    int numExecuted = 0;

    for (const auto& order : historicOrders) {
      auto st = order.getStatus();
      if (st == status::CANCELLED) {
        numCancelled++;
      }

      else if (st == status::EXECUTED) {
        numExecuted++;
      }
    }

    double cancelRatio = (numNew > 0) ? static_cast<double>(numCancelled) / static_cast<double>(numNew) : 0.0;
    double otr = (numNew > 0)? static_cast<double>(numNew) / static_cast<double>(numExecuted) : 0.0;// order to trade
    double const max_cancel = 0.8;
    double const min_otr = 1.5 * numNew;

    bool isStuffing =
       cancelRatio <= max_cancel && otr >= min_otr;
    if (isStuffing) {
      return Alert(order.getIdFirm(), this->getId(), FraudType::QUOTE_STUFFING, AlertSeverity::HIGH, AlertType::TECHNICAL, "Quote stuffing detected", order.getIdFirm());
    }



 }