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

-(void)testUnique
{
    BOOL eq;
    
    id unique_empty = [empty unique:^id(id obj) {
        return obj;
    }];
    eq = [empty elementsEqual:unique_empty];
    STAssertTrue(eq, @"Unique of empty array should be empty array");
    
    id unique_oneElem = [oneElem unique:^id(id obj) {
        return obj;
    }];
    eq = [oneElem elementsEqual:unique_oneElem];
    STAssertTrue(eq, @"Unique of single element array should be the same");
    
    id unique_numbers = [numbers unique:^id(id obj) {
        return obj;
    }];
    eq = [unique_numbers count] == 9 && [[numbers reduce:[NSNumber numberWithBool:YES] fn:^id(id acc, id obj) {
        return [NSNumber numberWithBool:([acc boolValue] && [unique_numbers contains:^BOOL(id obj2) {
            return [obj isEqual:obj2];
        }])];
    }] boolValue];
    STAssertTrue(eq, @"Unique test 1 with numbers: %@", unique_numbers);
    
    id unique_people = [people unique:^id(id obj) {
        return ((Person*)obj).name;
    }];
    eq = [unique_people count] == 6 && [[people reduce:[NSNumber numberWithBool:YES] fn:^id(id acc, id obj) {
        return [NSNumber numberWithBool:([acc boolValue] && [unique_people contains:^BOOL(id obj2) {
            return [((Person*)obj).name isEqualToString:((Person*)obj2).name];
        }])];
    }] boolValue];
    STAssertTrue(eq, @"Unique test 2 with people's name: %@", unique_people);
    
    id unique_people_age = [people unique:^id(id obj) {
        return ((Person*)obj).age;
    }];
    eq = [unique_people_age count] == 5 && [[people reduce:[NSNumber numberWithBool:YES] fn:^id(id acc, id obj) {
        return [NSNumber numberWithBool:([acc boolValue] && [unique_people_age contains:^BOOL(id obj2) {
            return [((Person*)obj).age isEqual:((Person*)obj2).age];
        }])];
    }] boolValue];
    STAssertTrue(eq, @"Unique test 3 with people's age: %@", unique_people_age);
    
    id unique_people_bestFriend = [people unique:^id(id obj) {
        return ((Person*)obj).bestFriend.name;
    }];
    eq = [unique_people_bestFriend count] == 4 && [[people reduce:[NSNumber numberWithBool:YES] fn:^id(id acc, id obj) {
        return [NSNumber numberWithBool:([acc boolValue] && [unique_people_bestFriend contains:^BOOL(id obj2) {
            return [((Person*)obj).bestFriend.name isEqualToString:((Person*)obj2).bestFriend.name];
        }])];
    }] boolValue];
    STAssertTrue(eq, @"Unique test 4 with people's best friend: %@", unique_people_bestFriend);
}

@end
