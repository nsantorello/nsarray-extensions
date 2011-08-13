#import <Foundation/Foundation.h>

@interface NSArray (Extensions)

-(BOOL)all:(BOOL(^)(id obj))fn;
-(BOOL)contains:(BOOL(^)(id obj))fn;
-(NSUInteger)count:(BOOL(^)(id obj))fn;
-(NSArray*)filter:(BOOL(^)(id obj))fn;
-(id)find:(BOOL(^)(id obj))fn;
-(NSArray*)findAll:(BOOL(^)(id obj))fn;
-(NSInteger)findIndex:(BOOL(^)(id obj))fn;
-(id)first;
-(NSArray*)first:(NSUInteger)n;
-(id)foldl:(id) acc fn:(id(^)(id acc, id obj))fn;
-(id)inject:(id) acc fn:(id(^)(id acc, id obj))fn;
-(NSArray*)map:(id(^)(id obj))fn;
-(BOOL)none:(BOOL(^)(id obj))fn;
-(BOOL)one:(BOOL(^)(id obj))fn;
-(NSArray*)partition:(BOOL(^)(id obj))fn;
-(id)reduce:(id) acc fn:(id(^)(id acc, id obj))fn;
-(NSArray*)select:(BOOL(^)(id obj))fn;
-(NSArray*)sort:(NSComparisonResult(^)(id obj1, id obj2))fn;
-(NSArray*)sortBy:(id(^)(id obj))fn;
-(NSArray*)take:(NSUInteger)n;
-(NSArray*)takeWhile:(BOOL(^)(id obj))fn;
-(NSArray*)unique:(id(^)(id obj))fn;

@end