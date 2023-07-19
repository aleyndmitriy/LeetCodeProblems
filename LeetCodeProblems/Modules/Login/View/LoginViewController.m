//
//  LoginViewController.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 10.04.23.
//

#import "LoginViewController.h"
#import "LoginViewOutput.h"
#import "LoginViewCellDelegate.h"

@interface LoginViewController()<UITableViewDelegate, UITableViewDataSource, UITableViewDataSourcePrefetching, LoginViewCellDelegate>
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (nonatomic, strong) id<LoginViewOutput> output;
@end

@implementation LoginViewController

-(instancetype)initWith:(id<LoginViewOutput>)presenter
{
    UIStoryboard * storyboard = [UIStoryboard storyboardWithName:@"Login" bundle:nil];
    self = [storyboard instantiateInitialViewController];
    if(self && [self isKindOfClass:[LoginViewController class]]) {
        self.output = presenter;
        return self;
    }
    else {
        return nil;
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
