//
//  NSArrayExtensionsAppDelegate.m
//  NSArrayExtensions
//
//  Created by Noah Santorello on 8/12/11.
//  Copyright 2011 Noah Santorello. All rights reserved.
//

#import "NSArrayExtensionsAppDelegate.h"
#import "NSArray+Extensions.h"

@interface Person : NSObject
{
    
}
@property (copy)NSString* name;
@property (copy)NSString* address;
@end
@implementation Person
@synthesize  name, address;

-(NSString*)description
{
    return [NSString stringWithFormat:@"Name: %@, Address: %@", name, address];
}

@end

@implementation NSArrayExtensionsAppDelegate

@synthesize window;


- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application
    NSArray* array = [NSArray arrayWithObjects:[NSNumber numberWithInt:1],
                      [NSNumber numberWithInt:2],
                      [NSNumber numberWithInt:2],
                      [NSNumber numberWithInt:3],
                      [NSNumber numberWithInt:1],
                      [NSNumber numberWithInt:2],
                      [NSNumber numberWithInt:2],
                      [NSNumber numberWithInt:3],
                      [NSNumber numberWithInt:-1],
                      nil];
    Person* p1 = [[Person alloc] init];
    p1.name = @"Andrew";
    p1.address = @"Shirley";
    Person* p2 = [[Person alloc] init];
    p2.name = @"Noah";
    p2.address = @"Buffalo";
    NSArray* peeps = [NSArray arrayWithObjects:p2, p1, nil];
    BOOL all = [array all:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] > 0;
    }];
    BOOL contains = [array contains:^BOOL(id obj) { // check to see if "array" contains "2"
        return [((NSNumber*)obj) intValue] == 4;
    }];
    BOOL none = [array none:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] == 3;
    }];
    BOOL one = [array one:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] == 1;
    }];
    NSNumber* reduce = [array reduce:[NSNumber numberWithInt:0] fn:^id(id acc, id obj) {
        return [NSNumber numberWithInt:([((NSNumber*)acc) intValue] + [((NSNumber*)obj) intValue] * [((NSNumber*)obj) intValue])];
    }];
    NSArray* filter = [array filter:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] < 3;
    }];
    NSArray* uniques = [array unique:^id(id obj) {
        return obj;
    }];
    NSArray* sortedUniques = [uniques sortBy:^id(id obj) {
        return obj;
    }];
    NSArray* find = [array find:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] == 0;
    }];
    NSInteger findIndex = [array findIndex:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] == 3;
    }];
    NSArray* take = [array take:6];
    NSArray* takeWhile = [array takeWhile:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] < 3;
    }];
    NSArray* sortBy = [peeps sortBy:^id(id obj) {
        return ((Person*)obj).address;
    }];
    NSArray* map = [peeps map:^id(id obj) {
        return ((Person*)obj).address;
    }];
    NSArray* partition = [array partition:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] <= 1;
    }];
    NSArray* drop = [array drop:0];
    NSDictionary* groupBy = [array groupBy:^id(id obj) {
        return obj;
    }];
}

@end
