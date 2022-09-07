Pod::Spec.new do |s|
  s.name = "RCBMWorkKit"
  s.version = "0.4.1"
  s.summary = "RCBMWorkKit."
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"asunrong"=>"gongjiahao@rongcloud.cn"}
  s.homepage = "https://gitee.com/rcbm/rcbm-ios-workbench-kit.git"
  s.description = "RCBMWorkKit description introduction \u5DE5\u4F5C\u53F0kit,SDWebImage adjust Beem; YYkit subspec for Beem"
  s.source = { :git => 'https://github.com/rongcloud-community/RCBMWorkKit.git', :tag => s.version.to_s }

 
  s.ios.deployment_target    = '9.0'
# s.ios.vendored_frameworks   = 'ios/RCBMWorkKit.framework' , 'ios/openssl.framework'
  s.ios.vendored_framework   = 'ios/RCBMWorkKit.xcframework', 'ios/openssl.framework'
  # s.public_header_files = 'ios/RCBMWorkKit.framework/Versions/A/Headers/RCBMWorkKitConfig.h'
  s.resource = 'ios/RCBMDefaultTheme.bundle'
# s.pod_target_xcconfig = {
#   'VALID_ARCHS' => 'arm64 x86_64',
##   'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
#   'ENABLE_BITCODE' => 'NO'
# }
  s.dependency 'AFNetworking', '~> 4.0.1'
# s.dependency 'YYKit','~> 1.0.9'
  s.dependency 'YYModel', '~> 1.0.4'
  s.dependency 'YYCategories', '~> 1.0.4'
  
  s.dependency 'Masonry', '~> 1.1.0'
  s.dependency 'SDWebImage', '~> 5.8'
#  s.dependency 'FMDB', '~> 2.7.5'
  s.dependency 'SSZipArchive', '~> 2.4.3'
  s.dependency 'MBProgressHUD', '~> 1.2.0'
end
