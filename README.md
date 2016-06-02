MobiKwik iOS SDK is a ready to use native solution for iOS applications (iOS 7 and above) to start accepting payments. This SDK provides both, fully functional user interface and API based methods for merchants who want to use their own interface.


## Payment Options
Based on requirements, merchants can choose from the following list of payment methods that are supported by SDK:
- MobiKwik Wallet Payments
- Card Payments
- Saved Cards
- Net Banking

>### Note
> All payment methods except MobiKwik Wallet, provide both UI and Non-UI functions. MobiKwik Wallet requires detailed user authorisation hence it contains it’s own UI.


## Prerequisites
Before starting with client integration process for your iOS application, please make sure that following steps and requirements have been met.
- **Merchant Identifier :** All MobiKwik merchants are provided with a unique merchant id e.g. MBK9002. You can find your merchant id and secret key in your MobiKwik [merchant account](https://wallet.mobikwik.com).
 
- **Merchant Checksum URL :** All network calls from SDK are checksum protected. This checksum is calculated by merchant server with a secret key which is available in your MobiKwik merchant account.

- **Merchant Response URL :** MobiKwik notifies merchant server at this URL regarding transaction’s state. This URL is also used for card, saved cards and netbanking payment methods.


## Installation

TestCocoaPod is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "TestCocoaPod"
```

## Author

Akashdeep, akashdeep@mobikwik.com

## License

TestCocoaPod is available under the MIT license. See the LICENSE file for more info.
