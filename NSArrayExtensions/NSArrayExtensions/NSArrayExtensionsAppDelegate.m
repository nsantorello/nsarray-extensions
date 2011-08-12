//
//  NSArrayExtensionsAppDelegate.m
//  NSArrayExtensions
//
//  Created by Noah Santorello on 8/11/11.
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
                      [NSNumber numberWithInt:3],
                      nil];
    BOOL val = [array all:^BOOL(id obj) {
        return [((NSNumber*)obj) intValue] > 0;
    }];
    NSNumber* num = [array foldl:[NSNumber numberWithInt:0] fn:^id(id acc, id obj) {
        return [NSNumber numberWithInt:([((NSNumber*)acc) intValue] + [((NSNumber*)obj) intValue] * [((NSNumber*)obj) intValue])];
    }];
}

@end
