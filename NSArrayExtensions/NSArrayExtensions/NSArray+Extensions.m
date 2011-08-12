//
//  NSArray+Extensions.m
//  NSArrayExtensions
//
//  Created by Noah Santorello on 8/11/11.
//  Copyright 2011 Noah Santorello. All rights reserved.
//

#import "NSArray+Extensions.h"

@implementation NSArray (Extensions)

-(BOOL)all:(BOOL(^)(id obj))fn
{
    NSNumber* trueNum = [NSNumber numberWithBool:TRUE];
    return [[self foldl:trueNum fn:^id(id acc, id obj) {
        //return [NSNumber numberWithBool:([((NSNumber*)acc) boolValue] && [[NSNumber numberWithBool:fn(obj)] boolValue])];//[((NSNumber*)obj) boolValue])];
        return [NSNumber numberWithBool:([((NSNumber*)acc) boolValue] && fn(obj))];
    }] boolValue];
}

-(id)foldl:(id) acc fn:(id(^)(id acc, id obj))fn
{
    id __block blockAcc = acc;
    [self enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
        blockAcc = [fn(blockAcc, obj) retain];
    }];
    
    return [blockAcc autorelease];
}

@end
