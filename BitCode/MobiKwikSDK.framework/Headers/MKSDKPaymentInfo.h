//
//  MKSDKPaymentInfo.h
//  MobiKwikSDK
//
//  Created by Akashdeep on 18/12/15.
//  Copyright © 2015 One Mobikwik Systems Pvt Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface MKSDKPaymentInfo : NSObject


/*!
 * @brief Email ID of the user attempting transaction.
 */
@property NSString *txnEmailID;
/*!
 * @brief Phone Number of the user attempting transaction.
 */
@property NSString *txnPhoneNo;
/*!
 * @brief Order ID of this transaction assigned by merchant.
 */
@property NSString *txnOrderID;
/*!
 * @brief MobiKwik merchant id assigned by MobiKwik to merchant e.g. MBK9002.
 */
@property NSString *txnMerchantMBKID;
/*!
 * @brief Merchant checksum url for fetching transaction checksum e.g. https://test.mobikwik.com/sdkchecksum.jsp
 */
@property NSString *txnMerchantChecksumURL;
/*!
 * @brief Merchant response url for posting transaction result e.g. https://test.mobikwik.com/sdkresponse.jsp
 */
@property NSString *txnMerchantResponseURL;
/*!
 * @brief Merchant saved cards url for fetching saved cards of the merchant e.g. https://test.mobikwik.com/prodfetchCards.jsp
 */
@property NSString *txnMerchantSavedCardURL;
/*!
 * @brief Set TRUE if you want to attempt transaction in sandbox mode. FALSE for production mode.
 */
@property BOOL txnModeSandbox;
/*!
 * @brief Merchant name used for communicating to user e.g. "You are paying Rs. 100 to SampleMerchant"
 */
@property NSString *txnMerchantName;
/*!
 * @brief Merchant logo image used for communication with user.
 */
@property UIImage *txnMerchantLogoImage;
/*!
 * @brief Calculated checksum of this transaction if you have already fetched checksum from your server.
 */
@property NSString *txnChecksum;
/*!
 * @brief Additional parameters and values in URL format with url encryption to get at merchant checksum url. This string will be directly added as the value of parameter 'extraParamString' in checksum request.
 */
@property NSString *txnExtraParameterString;
/*!
 * @brief Transaction amount in rupees.
 */
@property float     txnAmount;
/*!
 * @brief Set TRUE if you want SDK to print logs for debugging else FALSE.
 * @caution This flag is for debugging puposes only. Please turn it off when releasing APP.
 */
@property BOOL      txnPrintLogs;
/*!
 * @brief Set TRUE if you don't want to get notified that a bank page is loading slowly else False.
 */
@property BOOL     txnStopBankPageLoadTimer;
/*!
 * @brief Time after which SDK notifies merchant app that bank page is still loading. You can provide an option for user to either wait for it load or abort. Default value if set to 20 seconds. Any value below 5 seconds and above 60 seconds is set to default value. Works only when txnStopBankPageLoadTimer is left FALSE.
 */
@property float     txnBankPageLoadTime;


@end
