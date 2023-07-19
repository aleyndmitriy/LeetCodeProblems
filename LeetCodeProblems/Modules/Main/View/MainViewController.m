//
//  ViewController.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 31.03.23.
//

#import "MainViewController.h"
#import "MainViewOutput.h"
@interface MainViewController () <UITableViewDelegate, UITableViewDataSource, UITableViewDataSourcePrefetching>
{
    
}
@property (nonatomic, strong) id<MainViewOutput> output;
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (weak, nonatomic) IBOutlet UISearchBar *searchBar;

@end

@implementation MainViewController

-(instancetype)initWith:(id<MainViewOutput>)presenter
{
    UIStoryboard * storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    self = [storyboard instantiateInitialViewController];
    if(self && [self isKindOfClass:[MainViewController class]]) {
        self.output = presenter;
        return self;
    }
    else {
        return nil;
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
}


//--UITableViewDelegate methods


@end
