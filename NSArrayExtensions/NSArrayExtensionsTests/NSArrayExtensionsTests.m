//
//  NSArrayExtensionsTests.m
//  NSArrayExtensionsTests
//
//  Created by Noah Santorello on 8/12/11.
//  Copyright 2011 Noah Santorello. All rights reserved.
//

#import "NSArrayExtensionsTests.h"
#import "Person.h"
#import <NSArray+Extensions.h>

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
               [NSNumber numberWithInt:4],
               [NSNumber numberWithInt:-1],
               [NSNumber numberWithInt:1],
               [NSNumber numberWithInt:2],
               [NSNumber numberWithInt:-9],
               [NSNumber numberWithInt:-4],
               [NSNumber numberWithInt:-4],
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
    fred.age = [NSNumber numberWithInt:14];    
    
    abby.friend = fred;
    bob.friend = fred;
    carl.friend = debby;
    debby.friend = bob;
    earl.friend = abby;
    fred.friend = bob;
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
    STAssertEquals([[NSArray alloc] init], [empty unique], @"Ensure unique of empty array is empty array", <#...#>);
}

@end
