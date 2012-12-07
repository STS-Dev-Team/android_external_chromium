// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/*
Copyright (c) 2012, Motorola Mobility, Inc.
All Rights Reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of Motorola Mobility nor the names of its contributors
  may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// BEGIN Motorola, grp748, 04/16/2012, IKCOREAPP-877
#include "android/black_list_manager.h"
#include "base/memory/singleton.h"

#include "base/logging.h"

namespace net {
BlackListManager::BlackListManager() {
}

BlackListManager::~BlackListManager() {
}

// static
BlackListManager* BlackListManager::GetInstance() {
    return Singleton<BlackListManager>::get();
}

void BlackListManager::addRules(std::vector<std::string> blackList) {
    LOG(INFO)<<"BlackListManager::addRules  blackList size = "<<blackList.size();
    // remove all rules and add new ones.
    bypass_rules_.Clear();
    for (unsigned int i = 0; i < blackList.size(); i++)
        bypass_rules_.AddRuleFromString(blackList[i]);

    LOG(INFO)<<"Rules added : "<<bypass_rules_.ToString();
}

// BEGIN Motorola, grp748, 04/05/2012, IKMAIN-40160
void BlackListManager::clearRules() {
    LOG(INFO)<<"BlackListManager::clearRules";
    bypass_rules_.Clear();
}
// END IKMAIN-40160

} // namespace net
// END IKCOREAPP-877
