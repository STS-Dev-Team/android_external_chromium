// Copyright (c) 2012 The Chromium Authors. All rights reserved.
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
/**
 *  BlackListManager: Singleton class that add rules into
 *  ProxyBypassRules. Given a URL it matches with the added rules.
 */
#ifndef EXTERNAL_CHROMIUM_ANDROID_BLACK_LIST_MANAGER_H_
#define EXTERNAL_CHROMIUM_ANDROID_BLACK_LIST_MANAGER_H_
#pragma once

#include <string>
#include <vector>

#include "base/basictypes.h"
#include "net/base/net_export.h"
#include "net/proxy/proxy_bypass_rules.h"

template <typename T> struct DefaultSingletonTraits;

namespace net {
class NET_EXPORT BlackListManager {
  public:
    static BlackListManager* GetInstance();

    void addRules(std::vector<std::string> blackList);
    bool matchRule(const GURL& url) { return bypass_rules_.rules().empty() ? false : bypass_rules_.Matches(url); }
    // BEGIN Motorola, grp748, 04/05/2012, IKMAIN-40160
    void clearRules();
    // END IKMAIN-40160

  private:
    friend struct DefaultSingletonTraits<BlackListManager>;

    BlackListManager();
    ~BlackListManager();

    net::ProxyBypassRules bypass_rules_;

    DISALLOW_COPY_AND_ASSIGN(BlackListManager);
}; // class BlackListManager
} //namespace net
#endif // EXTERNAL_CHROMIUM_ANDROID_BLACK_LIST_MANAGER_H_
// END IKCOREAPP-877
