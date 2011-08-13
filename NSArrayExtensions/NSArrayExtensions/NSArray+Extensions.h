#import <Foundation/Foundation.h>

@interface NSArray (Extensions)

-(BOOL)all:(BOOL(^)(id obj))fn;
-(BOOL)any:(BOOL(^)(id obj))fn;
-(NSArray*)collect:(id(^)(id obj))fn;
-(BOOL)contains:(BOOL(^)(id obj))fn;
-(NSUInteger)count:(BOOL(^)(id obj))fn;
-(id)detect:(BOOL(^)(id obj))fn;
-(NSArray*)drop:(NSUInteger)n;
-(void)each:(void(^)(id obj))fn;
-(void)eachWithIndex:(void(^)(id obj, NSUInteger index))fn;
-(NSArray*)filter:(BOOL(^)(id obj))fn;
-(id)find:(BOOL(^)(id obj))fn;
-(NSArray*)findAll:(BOOL(^)(id obj))fn;
-(NSInteger)findIndex:(BOOL(^)(id obj))fn;
-(id)first;
-(NSArray*)first:(NSUInteger)n;
-(id)foldl:(id) acc fn:(id(^)(id acc, id obj))fn;
-(NSDictionary*)groupBy:(id(^)(id obj))fn;
-(id)inject:(id) acc fn:(id(^)(id acc, id obj))fn;
-(id)last;
-(NSArray*)map:(id(^)(id obj))fn;
-(id)max;
-(id)max:(NSComparisonResult(^)(id obj1, id obj2))fn;
-(id)maxBy:(id(^)(id obj))fn;
-(id)min;
-(id)min:(NSComparisonResult(^)(id obj1, id obj2))fn;
-(id)minBy:(id(^)(id obj))fn;
-(NSArray*)minMax;
-(NSArray*)minMax:(NSComparisonResult(^)(id obj1, id obj2))fn;
-(NSArray*)minMaxBy:(id(^)(id obj))fn;
-(BOOL)none:(BOOL(^)(id obj))fn;
-(BOOL)one:(BOOL(^)(id obj))fn;
-(NSArray*)partition:(BOOL(^)(id obj))fn;
-(id)reduce:(id) acc fn:(id(^)(id acc, id obj))fn;
-(NSArray*)select:(BOOL(^)(id obj))fn;
-(NSArray*)sort;
-(NSArray*)sort:(NSComparisonResult(^)(id obj1, id obj2))fn;
-(NSArray*)sortBy:(id(^)(id obj))fn;
-(NSArray*)take:(NSUInteger)n;
-(NSArray*)takeWhile:(BOOL(^)(id obj))fn;
-(NSArray*)unique:(id(^)(id obj))fn;

@end