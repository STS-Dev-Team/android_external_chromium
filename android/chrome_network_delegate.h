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

// BEGIN Motorola, grp748, 04/16/2012 IKCOREAPP-877
#ifndef CHROME_BROWSER_NET_CHROME_NETWORK_DELEGATE_H_
#define CHROME_BROWSER_NET_CHROME_NETWORK_DELEGATE_H_
#pragma once

#include "base/basictypes.h"
#include "net/base/network_delegate.h"
#include "net/base/net_export.h"
#include "net/base/net_errors.h"

namespace net {
class NET_EXPORT ChromeNetworkDelegate : public net::NetworkDelegate {
 public:
  ChromeNetworkDelegate();
  virtual ~ChromeNetworkDelegate();

 private:
  virtual int OnBeforeURLRequest(net::URLRequest* request,
                                 net::CompletionCallback* callback,
                                 GURL* new_url);
  virtual int OnBeforeSendHeaders(uint64 request_id,
                                  net::CompletionCallback* callback,
                                  net::HttpRequestHeaders* headers)
  { return net::OK; }
  virtual void OnResponseStarted(net::URLRequest* request) {}
  virtual void OnReadCompleted(net::URLRequest* request, int bytes_read) {}
  virtual void OnURLRequestDestroyed(net::URLRequest* request) {}
  virtual net::URLRequestJob* OnMaybeCreateURLRequestJob(
      net::URLRequest* request) { return NULL; }

  DISALLOW_COPY_AND_ASSIGN(ChromeNetworkDelegate);
};
} // namespace net
#endif // CHROME_BROWSER_NET_CHROME_NETWORK_DELEGATE_H_
// END IKCOREAPP-877
