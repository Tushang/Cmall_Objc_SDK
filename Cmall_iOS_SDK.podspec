#
# Be sure to run `pod lib lint Cmall_iOS_SDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'Cmall_iOS_SDK'
  s.version          = '0.0.2'
  s.summary          = 'Cmall iOS SDK'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/Tushang/Cmall_Objc_SDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Moyun' => 'moyunmo@hotmail.com' }
  s.source           = { :git => 'https://github.com/momo605654602@gmail.com/Cmall_iOS_SDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'
  s.frameworks = 'ImageIo', 'CoreMedia', 'AVFoundation','AssetsLibrary','MapKit','WebKit','Photos','MobileCoreServices','Accelerate','SystemConfiguration'
  s.vendored_frameworks = 'Cmall_iOS_SDK/CmallSDK.framework'

  # s.resource_bundles = {
  #   'Cmall_iOS_SDK' => ['CmallSDK.bundle']
  # }
  s.resources    = 'Cmall_iOS_SDK/CmallSDK.bundle'

  #s.source_files = 'Cmall_iOS_SDK/Classes/**/*'
  s.pod_target_xcconfig = { "OTHER_LDFLAGS" => "-ObjC -all_load" }

  # s.resource_bundles = {
  #   'Cmall_iOS_SDK' => ['Cmall_iOS_SDK/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
