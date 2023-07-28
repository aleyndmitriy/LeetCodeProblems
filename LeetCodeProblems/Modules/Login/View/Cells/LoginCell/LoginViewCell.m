//
//  LoginViewCell.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 10.04.23.
//

#import "LoginViewCell.h"

@interface LoginViewCell()

@property (weak, nonatomic) IBOutlet UILabel *lblStorageName;
@property (weak, nonatomic) IBOutlet UIImageView *imgName;
@property (weak, nonatomic) IBOutlet UIButton *btnLogin;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activity;
@property (weak, nonatomic) IBOutlet UIButton *btnLoadFolders;

@end

@implementation LoginViewCell

-(instancetype) initWithCoder:(NSCoder *)coder
{
    self = [super initWithCoder:coder];
    [_activity setHidesWhenStopped:YES];
    return self;
}

- (void)awakeFromNib {
    [super awakeFromNib];
    [_activity setHidesWhenStopped:YES];
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}
- (IBAction)btnLoginTouched:(UIButton *)sender {
    if(_loggedState == SignIn) {
        [_cellDelegate logOutFromService];
    } else {
        [_cellDelegate logInToService];
    }
}

- (IBAction)btnLoadFoldersTouched:(UIButton *)sender {
    [_cellDelegate loadStorage];
}

-(void) labelText:(NSString* _Nonnull)text imageName:(NSString* _Nonnull)imgName
{
    [_lblStorageName setText:text];
    UIImage* img = [UIImage imageNamed:imgName];
    [_imgName setImage:img];
}

-(void) updateLogInView
{
    [_btnLogin setEnabled:YES];
    [_btnLogin setTitle:LCLoginStateOut forState:UIControlStateNormal];
    [_btnLogin setBackgroundColor: [UIColor systemTealColor]];
    [_btnLoadFolders setEnabled:YES];
    [_activity stopAnimating];
}

-(void) updateLogOutView
{
    [_btnLogin setEnabled:YES];
    [_btnLogin setTitle:LCLoginStateIn forState:UIControlStateNormal];
    [_btnLogin setBackgroundColor: [UIColor systemBlueColor]];
    [_btnLoadFolders setEnabled:NO];
    [_activity stopAnimating];
}

-(void) updateProcessingView
{
    [_btnLogin setEnabled:NO];
    [_btnLogin setTitle:LCLoginStateProcessing forState:UIControlStateNormal];
    [_btnLoadFolders setEnabled:NO];
    [_activity startAnimating];
}

@end
