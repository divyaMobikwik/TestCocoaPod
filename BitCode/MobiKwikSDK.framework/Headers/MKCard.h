//
//  MKCard.h
//  MobiKwikSDK
//
//  Created by Akashdeep on 08/12/15.
//  Copyright © 2015 One Mobikwik Systems Pvt Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>




@interface MKCard : NSObject


/*!
 * @brief Card number of transacting credit/debit card.
 * @note Valid card number :
 
 * 13-19 digits long
 
 * Only numeric
 
 *Contains no
 * special characters or spaces.
 * @code Example
 Card_Object.card_Number = @"4012888888881881";
 */
@property NSString *card_Number;


/*!
 * @brief Expiry month of transacting credit/debit card.
 * @note Please pass card expiry month in MM format.
 * @attention For successful transaction , we need both expiry month and year. Do not forgot to add expiry year.
 * @code Example for October
 Card_Object.card_Expiry_Month_MM = @"10";
 */
@property NSString *card_Expiry_Month_MM;


/*!
 * @brief Expiry year of transacting credit/debit card.
 * @note Please pass card expiry year in YY format.
 * @attention For successful transaction , we need both expiry month and year. Do not forgot to add expiry month.
 * @code Example for year 2018
 Card_Object.card_Expiry_Year_YY = @"18";
 */
@property NSString *card_Expiry_Year_YY;


/*!
 * @brief CVV number for transacting credit/debit card.
 * @note Some cards do not require CVV number for transaction. For such cards, no need to add cvv.
 * @code Example
 Card_Object.card_CVV = @"123";
 */
@property NSString *card_CVV;




/*!
 * @brief Whether to save this card while making payment or not.
 * @code Example
 Card_Object.card_Save = TRUE;
 */
@property BOOL card_Save;




/*!
 * @brief Check if provided card information in card object is valid and sufficient for transaction or not.
 * @return NSError Object, Error code = 0 (SUCCESS) and Error code != 0 (FAILURE) and error description in NSLocalizedDescription
 * @code Example
 
 NSError *ValidationError = [Card_Object validate];
 
 if(ValidationError.Code != 0)
 {
    //Card is invalid
    int ErrorCode = ValidationError.code;
    NSString *ErrorReason = ValidationError.localizedFailureReason;
 }
 else
 {
    //Card is valid
 }
 */
-(NSError *)validate;





@end
