#pragma once

#include <memory>
#include <routing/Routing.pb.h>

void NetworkSend(mq::proto::routing::Address, std::unique_ptr<uint8_t[]>&& payload);
void Test();
