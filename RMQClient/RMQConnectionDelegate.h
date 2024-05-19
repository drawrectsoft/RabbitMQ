// This source code is dual-licensed under the Mozilla Public License ("MPL"),
// version 1.1 and the Apache License ("ASL"), version 2.0.
//
// The ASL v2.0:
//
// ---------------------------------------------------------------------------
// Copyright 2017-2019 Pivotal Software, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ---------------------------------------------------------------------------
//
// The MPL v1.1:
//
// ---------------------------------------------------------------------------
// The contents of this file are subject to the Mozilla Public License
// Version 1.1 (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// https://www.mozilla.org/MPL/
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
// License for the specific language governing rights and limitations
// under the License.
//
// The Original Code is RabbitMQ
//
// The Initial Developer of the Original Code is Pivotal Software, Inc.
// All Rights Reserved.
//
// Alternatively, the contents of this file may be used under the terms
// of the Apache Standard license (the "ASL License"), in which case the
// provisions of the ASL License are applicable instead of those
// above. If you wish to allow use of your version of this file only
// under the terms of the ASL License and not to allow others to use
// your version of this file under the MPL, indicate your decision by
// deleting the provisions above and replace them with the notice and
// other provisions required by the ASL License. If you do not delete
// the provisions above, a recipient may use your version of this file
// under either the MPL or the ASL License.
// ---------------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import "RMQChannel.h"

@class RMQConnection;
@protocol RMQConnectionDelegate <NSObject>

/// @brief Called when a socket cannot be opened, or when AMQP handshaking times out for some reason.
- (void)      connection:(RMQConnection *)connection
failedToConnectWithError:(NSError *)error;
/// @brief Called when a connection disconnects for any reason
- (void)   connection:(RMQConnection *)connection
disconnectedWithError:(NSError *)error;
/// @brief Called before the configured <a href="http://www.rabbitmq.com/api-guide.html#recovery">automatic connection recovery</a> sleep.
- (void)willStartRecoveryWithConnection:(RMQConnection *)connection;
/// @brief Called after the configured <a href="http://www.rabbitmq.com/api-guide.html#recovery">automatic connection recovery</a> sleep.
- (void)startingRecoveryWithConnection:(RMQConnection *)connection;
/*!
 * @brief Called when <a href="http://www.rabbitmq.com/api-guide.html#recovery">automatic connection recovery</a> has succeeded.
 * @param connection the connection instance that was recovered.
 */
- (void)recoveredConnection:(RMQConnection *)connection;
/// @brief Called with any channel-level AMQP exception.
- (void)channel:(id<RMQChannel>)channel
          error:(NSError *)error;
@end
