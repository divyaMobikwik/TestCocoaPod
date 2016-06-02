Pod::Spec.new do |s|
  s.name             = 'TestCocoaPod12321'
  s.version          = '1.0.0'
  s.summary          = 'Test framework for CocoaPod.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.platform = :ios, '7.0'
  s.description      = 'This is test framework for testing CocoaPod creation. This framework only prints a random string. Also, Sachin is the GOD of cricket and no one messes with him.'

  s.homepage         = 'https://github.com/AkashMobi/TestCocoaPod'
  s.license          = { :file => 'LICENSE' }
  s.author           = { 'Akashdeep' => 'akashdeep@mobikwik.com' }
  s.source           = { :git => 'https://github.com/AkashMobi/TestCocoaPod.git', :tag => '1.0.0' }

  #s.source_files = '*.framework'
  s.vendored_frameworks = 'TestFramework.framework'

end
