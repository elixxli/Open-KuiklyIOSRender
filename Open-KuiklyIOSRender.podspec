Pod::Spec.new do |spec|

  spec.name         = "Open-KuiklyIOSRender"
  spec.version      = "1.0.0-alpha.1"
  spec.summary      = "Supports Module ecosystem reuse for Kuikly and Hippy."
  spec.description  = <<-DESC
                    - tdf 公共代码库
                    - Modules extended by TDFModule are available for Kuikly and Hippy to share
                    - and existing Hippy Modules can also be quickly migrated to Kuikly
                   DESC

  spec.homepage     = "https://kuikly.tds.qq.com/"
  spec.license      = { :type => "Apache", :file => "Open-KuiklyIOSRender-1.0.0-alpha.1/LICENSE" }

  spec.author             = { "jonasluo" => "jonasluo@tencent.com" }
  spec.platform     = :ios, "9.0"
  spec.source       = { :http => "https://github.com/elixxli/Open-KuiklyIOSRender/archive/refs/tags/1.0.0-alpha.1.zip" }
  spec.vendored_frameworks = 'Open-KuiklyIOSRender-1.0.0-alpha.1/KuiklyIOSRender.xcframework'
  # spec.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  # spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  spec.pod_target_xcconfig = {
    'VALID_ARCHS[sdk=iphonesimulator*]' => 'arm64 x86_64'
  }
  spec.libraries    = "c++"
  spec.public_header_files = 'Open-KuiklyIOSRender-1.0.0-alpha.1/KuiklyIOSRender.xcframework/**/*.h'
  spec.source_files = 'Open-KuiklyIOSRender-1.0.0-alpha.1/KuiklyIOSRender.xcframework/**/*.h'
end
