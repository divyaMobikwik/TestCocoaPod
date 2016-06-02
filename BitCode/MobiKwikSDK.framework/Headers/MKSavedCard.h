//
//  MKSavedCard.h
//  MobiKwikSDK
//
//  Created by Akashdeep on 08/12/15.
//  Copyright © 2015 One Mobikwik Systems Pvt Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>




@interface MKSavedCard : NSObject


@property NSString *savedCard_CardName;
@property NSString *savedCard_CardId;
@property NSString *savedCard_First4;
@property NSString *savedCard_Last4;
@property NSString *savedCard_CardNumber;
@property NSString *savedCard_CardType;
@property NSString *savedCard_CVV;


/*
{
    "cardHolderName": "akashdeep2991",
    "first4": "5534",
    "last4": "7007",
    "cardId": "550c3e33bc3ce553c5087ac5ad3b3fe757eeb2923c67398f6293d835d9~2528123",
    "cardType": "Mastercard",
    "formattedCardNum": "5534 XXXX XXXX 7007"
}
*/
-(instancetype)initWithDictionary:(NSDictionary *)savedcardDictionary;


@end
