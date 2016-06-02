Pod::Spec.new do |s|
  s.name             = 'TestCocoaPod12321'
  s.version          = '1.0.0'
  s.summary          = 'Test framework for CocoaPod.'
  s.platform = :ios, '7.0'
  s.description      = 'This is test framework for testing CocoaPod creation. This framework only prints a random string. Also, Sachin is the GOD of cricket and no one messes with him.'

  s.homepage         = 'https://github.com/AkashMobi/TestCocoaPod'
  s.license          = { :file => 'LICENSE', :type => 'MIT' }
  s.author           = { 'Akashdeep' => 'akashdeep@mobikwik.com' }
  s.source           = { :git => 'https://github.com/AkashMobi/TestCocoaPod.git', :tag => '1.0.0' }
  s.vendored_frameworks = 'TestFramework.framework'

  s.subspec 'BitCode' do |bc|
    bc.vendored_framework = 'BitCode/TestFrameworkBC.framework'
  end
end
