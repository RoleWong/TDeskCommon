Pod::Spec.new do |spec|
  spec.name         = 'TDeskCommon'
  spec.version      = '2.9.01'
  spec.platform     = :ios
  spec.ios.deployment_target = '9.0'
  spec.license      = { :type => 'Proprietary',
      :text => <<-LICENSE
        copyright 2017 Tencent Ltd. All rights reserved.
        LICENSE
       }
  spec.homepage     = 'https://cloud.tencent.com/document/product/269/3794'
  spec.documentation_url = 'https://cloud.tencent.com/document/product/269/9147'
  spec.authors      = 'Tencent Cloud Desk'
  spec.summary      = 'TIMCommon'
  
#  spec.vendored_frameworks = 'ReactiveObjCForTDesk.framework'
  
  spec.dependency 'TDeskCore', '~> 2.9.01'
  spec.dependency 'SDWebImage'
  spec.dependency 'ReactiveObjCForTDesk', '~> 5.0.3'
  spec.dependency 'MasonryForTDesk'
  spec.requires_arc = true

  spec.source = { :git => 'https://github.com/RoleWong/TDeskCommon.git', :tag => spec.version}

  spec.source_files = '**/*.{h,m,mm,c}'

  spec.resource = ['Resources/*.bundle']
  spec.resource_bundle = {
    "#{spec.module_name}_Privacy" => 'Resources/PrivacyInfo.xcprivacy'
  }

end

