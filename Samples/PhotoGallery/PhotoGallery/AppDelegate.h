/*
 * Copyright (C) 2016 Buddy Platform, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

#import <UIKit/UIKit.h>

@class MainViewController;
@class PictureList;

#import <BuddySDK/BuddyClientProtocol.h>

#define CommonAppDelegate (AppDelegate*)[[UIApplication sharedApplication] delegate]

@interface AppDelegate : UIResponder <UIApplicationDelegate,BPClientDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (nonatomic,strong) UINavigationController *navController;
@property (nonatomic,strong) MainViewController *topController;
@property (nonatomic,assign) BOOL loginPresented;

@property (nonatomic,strong) PictureList *userPictures;

-(void) storeUsername:(NSString*)userName;
-(NSString*) fetchUsername;
-(BOOL) isUsernameSet;

// Used on logout and also if user changes after authFailure
-(void) clearDownloadedData;

// Executes Buddy Logout and clears downloaded data
-(void) doLogout;

/* Store password in a more secure place than User Preferences in a real App */
-(void) storePassword:(NSString*)userName;
-(NSString*) fetchPassword;
-(BOOL) isPasswordSet;

-(void) storeUsername:(NSString *)userName andPassword:(NSString*)password;

-(void)authorizationNeedsUserLogin;

@end
