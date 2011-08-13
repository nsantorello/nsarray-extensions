//
//  NSArrayExtensionsAppDelegate.m
//  NSArrayExtensions
//
//  Created by Noah Santorello on 8/12/11.
//  Copyright 2011 Noah Santorello. All rights reserved.
//

#import "NSArrayExtensionsAppDelegate.h"
#import "NSArray+Extensions.h"

@implementation NSArrayExtensionsAppDelegate

@synthesize window;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application
    NSArray* array = [NSArray arrayWithObjects:[NSNumber numberWithInt:1],
                      [NSNumber numberWithInt:2],
                      [NSNumber numberWithInt:2],
                      [NSNumber numberWithInt:3],
                      nil];
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
    NSArray* find = [array find:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] == 0;
    }];
    NSInteger findIndex = [array findIndex:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] == 3;
    }];
}

@end
