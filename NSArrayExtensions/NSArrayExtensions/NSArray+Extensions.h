//
//  NSArray+Extensions.h
//  NSArrayExtensions
//
//  Created by Noah Santorello on 8/11/11.
//  Copyright 2011 Noah Santorello. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (Extensions)
    
-(BOOL)all:(BOOL(^)(id obj))fn;
-(id)foldl:(id) acc fn:(id(^)(id acc, id obj))fn;

@end
