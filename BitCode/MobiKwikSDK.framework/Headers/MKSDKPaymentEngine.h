//
//  MKSDKPaymentEngine.h
//  MobiKwikSDK
//
//  Created by Akashdeep on 18/12/15.
//  Copyright © 2015 One Mobikwik Systems Pvt Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MKSDKPaymentInfo.h"
#import "MKCard.h"
#import "MKSavedCard.h"



@protocol MKSDKPaymentDelegate <NSObject>


@required


/*!
 * @brief Delegate method called whenever payment request is completed successfuly.
 * @param payment Object of MKSDKPaymentInfo which is finished processing.
 */

-(void)mksdkPaymentSucceeded:(MKSDKPaymentInfo *)payment;


/*!
 * @brief Delegate method called whenever payment request failed to complete.
 * @param payment Object of MKSDKPaymentInfo which is finished processing.
 * @param failError Object of NSError containing error code in failError.code and description in failError.localizedDescription.
 */

-(void)mksdkPaymentFailed:(MKSDKPaymentInfo *)payment withError:(NSError *)failError;


@optional


/*!
 * @brief Delegate method called in case of non UI support payment requests.
 * @param payment Object of MKSDKPaymentInfo which is finished processing.
 * @param webview Object of UIWebView loading bank redirections.
 */

-(void)mksdkPaymentInitiated:(MKSDKPaymentInfo *)payment inWebview:(UIWebView *)webview;


/*!
 * @brief Delegate method called whenever a loading bank page hit timeout value provided payment request.
 */

-(void)mksdkPaymentHitTimeOut;


/*!
 * @brief Delegate method called whenever bank page started loading.
 */

-(void)mksdkPaymentWebpageStartedLoading;


/*!
 * @brief Delegate method called whenever bank page stopped loading.
 */

-(void)mksdkPaymentWebpageStoppedLoading;


@end




@interface MKSDKPaymentEngine : NSObject


@property (nonatomic, weak) id<MKSDKPaymentDelegate> delegate;


+(id)sharedManager;


/* -------------------------------------------------------------------------------- */
//                          UI SUPPORT PAYMENT REQUESTS
/* -------------------------------------------------------------------------------- */


/*!
 * @brief Starts payment request with SDK built in UI. Payment options visible for users are Credit Card, Debit Card, Net Banking, Saved Cards(if available) and MobiKwik Wallet payment. SDK will take care of all the UI needs and provide response with delegate methods mksdkPaymentSucceeded: and mksdkPaymentFailed:
 * @param payment Object of MKSDKPaymentInfo containing all the required payment information.
 */

-(void)mksdkStartPayment:(MKSDKPaymentInfo *)payment;


/*!
 * @brief Starts payment request with built in card page and bank redirects UI for users to interact. User will straight away see the credit card page and no other payment option will be visible. SDK will take care of all the UI needs necessory for credit card payment and provide response with delegate methods mksdkPaymentSucceeded: and mksdkPaymentFailed:
 * @param payment Object of MKSDKPaymentInfo containing all the required payment information.
 */

-(void)mksdkStartCreditCardPayment:(MKSDKPaymentInfo *)payment;


/*!
 * @brief Starts payment request with built in card page or debit card bank selection based on options fetched from server. SDK will take care of all the UI needs necessory for debit card payment and provide response with delegate methods mksdkPaymentSucceeded: and mksdkPaymentFailed:
 * @param payment Object of MKSDKPaymentInfo containing all the required payment information.
 */

-(void)mksdkStartDebitCardPayment:(MKSDKPaymentInfo *)payment;


/*!
 * @brief Starts payment request with built in bank selection page where user selects his/her bank for payment. SDK will take care of all the UI needs necessory from bank selection to bank redirects and provide response with delegate methods mksdkPaymentSucceeded: and mksdkPaymentFailed:
 * @param payment Object of MKSDKPaymentInfo containing all the required payment information.
 */

-(void)mksdkStartSavedCardPayment:(MKSDKPaymentInfo *)payment;


/*!
 * @brief Starts payment request with built in bank selection page where user selects his/her bank for payment. SDK will take care of all the UI needs necessary from bank selection to bank redirects and provide response with delegate methods mksdkPaymentSucceeded: and mksdkPaymentFailed:
 * @param payment Object of MKSDKPaymentInfo containing all the required payment information.
 */

-(void)mksdkStartNetbankingPayment:(MKSDKPaymentInfo *)payment;


/*!
 * @brief Starts payment request with built in UI for MobiKwik payment flow. SDK will choose user flow path based on your instruction of whether to credit or debit user's wallet. In case user falls short of wallet balance while paying, SDK will provide options and switch user flow to add money in MobiKwik wallet balance. SDK will take care of all the UI needs and provide response with delegate methods mksdkPaymentSucceeded: and mksdkPaymentFailed:
 * @param payment Object of MKSDKPaymentInfo containing all the required payment information.
 * @param isAmountCredit Set TRUE if you want user to add given amount in his/her MobiKwik Wallet balance else FALSE if you want to deduct given ammount from users Mobikwik Wallet balance.
 */

-(void)mksdkStartMobiKwikPayment:(MKSDKPaymentInfo *)payment addMoneyToAccount:(BOOL)isAmountCredit;











/* -------------------------------------------------------------------------------- */
//                        NO UI SUPPORT PAYMENT REQUESTS
/* -------------------------------------------------------------------------------- */


/*!
 * @brief Starts payment request with provided payment and card info. Merchant app has to handle all the UI for collecting card information. SDK will handle all the payment process and provide an instance of UIWebView running bank redirects with delegate method mksdkPaymentInitiated: inWebview:. Payment success and failure results will be provided in delegate methods mksdkPaymentSucceeded: and mksdkPaymentFailed: respectively.
 * @param payment Object of MKSDKPaymentInfo containing all the required payment information.
 * @param card Object of MKCard containing all the required card information.
 */

-(void)mksdkStartCreditCardPayment:(MKSDKPaymentInfo *)payment withCard:(MKCard *)card;


/*!
 * @brief Starts payment request with provided payment and card info. Merchant app has to handle all the UI for collecting card information. SDK will handle all the payment process and provide an instance of UIWebView running bank redirects with delegate method mksdkPaymentInitiated: inWebview:. Payment success and failure results will be provided in delegate methods mksdkPaymentSucceeded: and mksdkPaymentFailed: respectively.
 * @param payment Object of MKSDKPaymentInfo containing all the required payment information.
 * @param card Object of MKCard containing all the required card information.
 */

-(void)mksdkStartDebitCardPayment:(MKSDKPaymentInfo *)payment withCard:(MKCard *)card;


/*!
 * @brief Starts payment request with provided payment and saved card info. Merchant app has to handle all the UI for collecting saved card information. SDK will handle all the payment process and provide an instance of UIWebView running bank redirects with delegate method mksdkPaymentInitiated: inWebview:. Payment success and failure results will be provided in delegate methods mksdkPaymentSucceeded: and mksdkPaymentFailed: respectively.
 * @param payment Object of MKSDKPaymentInfo containing all the required payment information.
 * @param savedCard Object of MKSavedCard containing all the required saved card information.
 */

-(void)mksdkStartSavedCardPayment:(MKSDKPaymentInfo *)payment withCard:(MKSavedCard *)savedCard;


/*!
 * @brief Starts payment request with provided payment info and bank ID. Merchant app has to handle all the UI for collecting bank ID of the selected bank. SDK will handle all the payment process and provide an instance of UIWebView running bank redirects with delegate method mksdkPaymentInitiated: inWebview:. Payment success and failure results will be provided in delegate methods mksdkPaymentSucceeded: and mksdkPaymentFailed: respectively.
 * @param payment Object of MKSDKPaymentInfo containing all the required payment information.
 * @param bankId String representation of the ID corresponding to selected bank.
 */

-(void)mksdkStartNetbankingPayment:(MKSDKPaymentInfo *)payment withBankID:(NSString *)bankId;




@end
