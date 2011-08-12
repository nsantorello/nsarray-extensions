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
-(id)foldl:(id) acc fn:(id(^)(id acc, id obj))fn;
-(BOOL)none:(BOOL(^)(id obj))fn;
-(BOOL)one:(BOOL(^)(id obj))fn;
-(NSArray*)select:(BOOL(^)(id obj))fn;
-(NSArray*)unique:(id(^)(id obj))fn;

@end