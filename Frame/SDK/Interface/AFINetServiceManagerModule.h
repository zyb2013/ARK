﻿/*
* This source file is part of ArkGameFrame
* For the latest info, see https://github.com/ArkGame
*
* Copyright (c) 2013-2017 ArkGame authors.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

#pragma once

#include "SDK/Interface/AFIModule.h"
#include "AFINetServerService.h"
#include "AFINetClientService.h"

namespace ark
{

    class AFINetServiceManagerModule : public AFIModule
    {
    public:
        //server-side net service
        virtual int CreateServer() = 0;
        virtual AFINetServerService* GetSelfNetServer() = 0;

        virtual int CreateClusterClients() = 0;
        virtual int CreateClusterClient(const int bus_id, const std::string& url) = 0;

        virtual AFINetClientService* GetNetClientService(const uint8_t& app_type) = 0;
        virtual AFINetClientService* GetNetClientServiceByBusID(const int bus_id) = 0;

        virtual bool AddNetConnectionBus(int client_bus_id, AFINet* net_server_ptr) = 0;
        virtual bool RemoveNetConnectionBus(int client_bus_id) = 0;
        virtual AFINet* GetNetConnectionBus(int src_bus, int target_bus) = 0;
    };

}