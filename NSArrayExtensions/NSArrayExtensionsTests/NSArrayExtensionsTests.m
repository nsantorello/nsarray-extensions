//
//  NSArrayExtensionsTests.m
//  NSArrayExtensionsTests
//
//  Created by Noah Santorello on 8/12/11.
//  Copyright 2011 Noah Santorello. All rights reserved.
//

#import "NSArrayExtensionsTests.h"

@implementation NSArrayExtensionsTests

@synthesize empty, oneElem, numbers, people;

#pragma mark - Setup/Teardown

- (void)setUp
{
    [super setUp];
    
    // Set-up code here.
    empty = [[NSArray alloc] init];
    oneElem = [NSArray arrayWithObject:[NSNumber numberWithInt:8]];
    
    numbers = [NSArray arrayWithObjects:
               [NSNumber numberWithInt:18],
               [NSNumber numberWithInt:4],
               [NSNumber numberWithInt:-4],
               [NSNumber numberWithInt:-1],
               [NSNumber numberWithInt:1],
               [NSNumber numberWithInt:2],
               [NSNumber numberWithInt:-9],
               [NSNumber numberWithInt:-4],
               [NSNumber numberWithInt:4],
               [NSNumber numberWithInt:0],
               [NSNumber numberWithInt:9],
               nil];
    
    Person* abby = [[Person alloc] init];
    abby.name = @"Abby";
    abby.age = [NSNumber numberWithInt:25];
    Person* bob = [[Person alloc] init];
    bob.name = @"Bob";
    bob.age = [NSNumber numberWithInt:27];
    Person* carl = [[Person alloc] init];
    carl.name = @"Carl";
    carl.age = [NSNumber numberWithInt:22];
    Person* debby = [[Person alloc] init];
    debby.name = @"Debby";
    debby.age = [NSNumber numberWithInt:34];
    Person* earl = [[Person alloc] init];
    earl.name = @"Earl";
    earl.age = [NSNumber numberWithInt:51];
    Person* fred = [[Person alloc] init];
    fred.name = @"Fred";
    fred.age = [NSNumber numberWithInt:27];    
    
    abby.bestFriend = fred;
    bob.bestFriend = fred;
    carl.bestFriend = debby;
    debby.bestFriend = bob;
    earl.bestFriend = abby;
    fred.bestFriend = bob;
    
    people = [NSArray arrayWithObjects:abby, bob, carl, debby, earl, fred, nil];
    
    [abby release];
    [bob release];
    [carl release];
    [debby release];
    [earl release];
    [fred release];
}

- (void)tearDown
{
    // Tear-down code here.
    empty = nil;
    oneElem = nil;
    numbers = nil;
    people = nil;
    [super tearDown];
}

#pragma mark - any:

-(void)testAnyEmpty
{
    BOOL any = [empty any:^BOOL(id obj) {
        return YES;
    }];
    STAssertFalse(any, @"always return false for empty arrays");
    any = [empty any:^BOOL(id obj) {
        return NO;
    }];
    STAssertFalse(any, @"always return false for empty arrays (2)");
}

-(void)testAnyOneElem
{
    BOOL any = [oneElem any:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] == 8;
    }];
    STAssertTrue(any, @"true for 8 == 8");
    any = [oneElem any:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] == 7;
    }];
    STAssertFalse(any, @"false for 7 == 8");
}

-(void)testAnyNumbers
{
    BOOL any = [numbers any:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] == 9;
    }];
    STAssertTrue(any, @"true for the 9 in array");
    any = [numbers any:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] == 8;
    }];
    STAssertFalse(any, @"false since no 8's in array");
}

-(void)testAnyPeople
{
    BOOL any = [people any:^BOOL(id obj) {
        return [((Person*)obj).name isEqualToString:@"Fred"];
    }];
    STAssertTrue(any, @"true for \"Fred\" being a name in array");
    any = [people any:^BOOL(id obj) {
        return [((Person*)obj).name isEqualToString:@"Gary"];
    }];
    STAssertFalse(any, @"false since no \"Gary\" in array");
    any = [people any:^BOOL(id obj) {
        return [((Person*)obj).age intValue] == 27;
    }];
    STAssertTrue(any, @"true for age of 27");
    any = [people any:^BOOL(id obj) {
        return [((Person*)obj).age intValue] == 26;
    }];
    STAssertFalse(any, @"false since no 26");
    any = [people any:^BOOL(id obj) {
        return [((Person*)obj).bestFriend.name isEqualToString:@"Fred"];
    }];
    STAssertTrue(any, @"true for \"Fred\" being a best friend's name");
    any = [people any:^BOOL(id obj) {
        return [((Person*)obj).bestFriend.name isEqualToString:@"Carl"];
    }];
    STAssertFalse(any, @"false since no best friend named \"Carl\"");
}

#pragma mark - min
-(void)testMinEmpty
{
    id min = [empty min];
    STAssertNil(min, @"true for min of empty array");
}

-(void)testMinOneElem
{
    NSNumber* min = [oneElem min];
    BOOL eq = [min intValue] == 8;
    STAssertTrue(eq, @"true for min of [8] is 8");
}

-(void)testMinNumbers
{
    NSNumber* min = [numbers min];
    BOOL eq = [min intValue] == -9;
    STAssertTrue(eq, @"true that min of test numbers array is -9");
}

-(void)testMinPeople
{
    Person* min = [people min];
    BOOL eq = [min.name isEqualToString:@"Abby"];
    STAssertTrue(eq, @"true that min properly uses compare: to compare two custom objects");
}

#pragma mark - unique:

-(void)testUniqueEmpty
{
    id unique_empty = [empty unique:^id(id obj) {
        return obj;
    }];
    BOOL eq = [empty elementsEqual:unique_empty];
    STAssertTrue(eq, @"true for empty array");
}

-(void)testUniqueOneElem
{
    id unique_oneElem = [oneElem unique:^id(id obj) {
        return obj;
    }];
    BOOL eq = [oneElem elementsEqual:unique_oneElem];
    STAssertTrue(eq, @"true for single element unique");
}

-(void)testUniqueNumbers
{
    id unique_numbers = [numbers unique:^id(id obj) {
        return obj;
    }];
    BOOL eq = [unique_numbers count] == 9 && [[numbers reduce:[NSNumber numberWithBool:YES] fn:^id(id acc, id obj) {
        return [NSNumber numberWithBool:([acc boolValue] && [unique_numbers contains:^BOOL(id obj2) {
            return [obj isEqual:obj2];
        }])];
    }] boolValue];
    STAssertTrue(eq, @"true for unique with numbers: %@", unique_numbers);
}

-(void)testUniquePeople
{
    id unique_people = [people unique:^id(id obj) {
        return ((Person*)obj).name;
    }];
    BOOL eq = [unique_people count] == 6 && [[people reduce:[NSNumber numberWithBool:YES] fn:^id(id acc, id obj) {
        return [NSNumber numberWithBool:([acc boolValue] && [unique_people contains:^BOOL(id obj2) {
            return [((Person*)obj).name isEqualToString:((Person*)obj2).name];
        }])];
    }] boolValue];
    STAssertTrue(eq, @"true for unique by people's name: %@", unique_people);
    
    id unique_people_age = [people unique:^id(id obj) {
        return ((Person*)obj).age;
    }];
    eq = [unique_people_age count] == 5 && [[people reduce:[NSNumber numberWithBool:YES] fn:^id(id acc, id obj) {
        return [NSNumber numberWithBool:([acc boolValue] && [unique_people_age contains:^BOOL(id obj2) {
            return [((Person*)obj).age isEqual:((Person*)obj2).age];
        }])];
    }] boolValue];
    STAssertTrue(eq, @"true for unique by people's age: %@", unique_people_age);
    
    id unique_people_bestFriend = [people unique:^id(id obj) {
        return ((Person*)obj).bestFriend.name;
    }];
    eq = [unique_people_bestFriend count] == 4 && [[people reduce:[NSNumber numberWithBool:YES] fn:^id(id acc, id obj) {
        return [NSNumber numberWithBool:([acc boolValue] && [unique_people_bestFriend contains:^BOOL(id obj2) {
            return [((Person*)obj).bestFriend.name isEqualToString:((Person*)obj2).bestFriend.name];
        }])];
    }] boolValue];
    STAssertTrue(eq, @"true for unique by people's best friend: %@", unique_people_bestFriend);
}

@end
