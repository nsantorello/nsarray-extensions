// TODO: (ns): throw exceptions within functions if fn == nil
// TODO: (ns): make sure my library doesn't throw exceptions for weird array or fn input

#import "NSArray+Extensions.h"

@implementation NSArray (Extensions)

-(BOOL)all:(BOOL(^)(id obj))fn
{    
    __block BOOL all = true;
    
    [self enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
        all = all && fn(obj);
    }];
    
    return all;
}

-(BOOL)contains:(BOOL(^)(id obj))fn
{
    return [self count:fn] > 0;
}

-(NSInteger)count:(BOOL(^)(id obj))fn
{
    __block int count = 0;
    
    [self enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
        if (fn(obj))
        {
            count++;
        }
    }];
    
    return count;
}

-(NSArray*)filter:(BOOL(^)(id obj))fn
{
    __block NSMutableArray* filtered = [[NSMutableArray alloc] init];
    
    [self enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
        if (fn(obj))
        {
            [filtered addObject:obj];
        }
    }];
    
    return [filtered autorelease];
}

-(NSArray*)findAll:(BOOL(^)(id obj))fn
{
    return [[self filter:fn] autorelease];
}

-(id)first
{
    return [self count] == 0 ? nil : [self objectAtIndex:0];
}

-(id)foldl:(id) acc fn:(id(^)(id acc, id obj))fn
{
    // TODO: (ns): there is probably a memory leak in this function.
    __block id blockAcc = acc;
    [self enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
        blockAcc = [fn(blockAcc, obj) retain];
    }];
    
    return [blockAcc autorelease];
}

-(BOOL)none:(BOOL(^)(id obj))fn
{
    return [self count:fn] == 0;
}

-(BOOL)one:(BOOL(^)(id obj))fn
{
    return [self count:fn] == 1;
}

-(NSArray*)select:(BOOL(^)(id obj))fn
{
    return [[self filter:fn] autorelease];
}

-(NSArray*)unique:(id(^)(id obj))fn
{
    __block NSMutableArray* uniques = [[[NSMutableArray alloc] init] autorelease];
    
    [self enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
        if (![uniques contains:^BOOL(id obj2) {
            return [fn(obj) isEqual:fn(obj2)];
        }])
        {
            [uniques addObject:obj];
        }
    }];
    
    return uniques;
}

@end