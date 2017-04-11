//
//  CMViewController.m
//  Cmall_iOS_SDK
//
//  Created by momo605654602@gmail.com on 04/10/2017.
//  Copyright (c) 2017 momo605654602@gmail.com. All rights reserved.
//

#import "CMViewController.h"
#import <CmallSDK/CmallSDK.h>

@interface CMViewController ()

@property (weak, nonatomic) IBOutlet UITextView *outputDataText;

@end

@implementation CMViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    /*
     [CmallSDK showWithUserDefined:^(NSInteger code, NSString *infoDes) {
     NSLog(@"要开始转菊花了");
     }];
     
     [CmallSDK dismissWithUserDefined:^{
     NSLog(@"关闭菊花");
     }];
     */
    __weak typeof(self) weakSelf = self;
    [CmallSDK setBuyNowCallBack:^(NSDictionary* uploadDict,NSString* modelJson,NSString * _Nullable editFace){
        NSLog(@"====我买了这个定制====");
        NSLog(@"====需要第三方上传====");
        NSLog(@"====%@====",uploadDict);
        NSLog(@"====给第三方的大JSON====");
        NSLog(@"====%@====",modelJson);
        NSLog(@"====给第三方的editface====");
        NSLog(@"====%@====",editFace);
        NSString *message = [NSString stringWithFormat:@"我买了这个定制,下面是SDK吐出的信息\n uploadDict：%@\nmodelJson：%@\neditFace:%@",uploadDict,modelJson,editFace];
        
        weakSelf.outputDataText.text = message;
    }];
    [CmallSDK setNormalErrorCallBack:^(NSInteger code,NSString* errorDesc,NSDictionary * _Nullable errInfo){
        NSLog(@"====TudeSDK普通错误====");
        NSLog(@"====错误码：%ld，错误原因：%@，错误info：%@",code,errorDesc,errInfo);
        NSString *message = [NSString stringWithFormat:@"TudeSDK普通错误\n错误码：%ld，错误原因：%@，错误信息：%@",code,errorDesc,errInfo];
        
        weakSelf.outputDataText.text = message;
    }];
    
    
    self.outputDataText.layer.borderWidth = 1.0f;
    self.outputDataText.layer.borderColor = [UIColor greenColor].CGColor;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)startDIYAction:(id)sender {
    
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:NSLocalizedString(@"温馨提示",@"") message:NSLocalizedString(@"请确保所填图片url是允许跨域的！！！",@"") preferredStyle:UIAlertControllerStyleAlert];
    [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.placeholder = @"自定义图片url(以http打头的全路径)";
    }];
    __weak typeof(self) weakSelf = self;
    [alertController addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"使用自定义图片URL，宽高未知",@"") style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        NSString *imgUrl = alertController.textFields.firstObject.text;
        if (imgUrl.length && [imgUrl hasPrefix:@"http"]) {
            [CmallSDK setInitImageUrl:imgUrl imageWidth:0 imageHeight:0];
            [CmallSDK showAutoListViewControllerWithCurrentViewController:weakSelf];
        }
    }]];
    [alertController addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"使用预设图片，宽高已知",@"") style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [CmallSDK setInitImageUrl:@"https://image.cmall.com/imgsrv/artsrelease/322891/o_1ajl81bmh1iaq15rhtj113ao1r309.jpg" imageWidth:3000 imageHeight:2002];
        [CmallSDK showAutoListViewControllerWithCurrentViewController:weakSelf];
    }]];
    
    [alertController addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"取消",@"") style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
    }]];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

@end
