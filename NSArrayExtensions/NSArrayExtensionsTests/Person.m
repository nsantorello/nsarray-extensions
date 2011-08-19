//
//  Person.m
//  NSArrayExtensions
//
//  Created by Noah Santorello on 8/13/11.
//  Copyright 2011 Noah Santorello. All rights reserved.
//

#import "Person.h"


@implementation Person

@synthesize name, age, bestFriend;

-(id)copyWithZone:(NSZone *)zone
{
    return self;
}

-(NSString*)description
{
    return [NSString stringWithFormat:@"Name: %@. Age: %@. BFF: %@.", name, age, bestFriend.name];
}

-(NSComparisonResult)compare:(id)object
{
    return [name compare:((Person*)object).name];
}

@end
