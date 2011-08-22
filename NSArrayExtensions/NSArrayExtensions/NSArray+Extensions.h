#import <Foundation/Foundation.h>

@interface NSArray (Extensions)

/* Checks to see if all objects in the array satisfy a condition.
 * 
 * fn - block condition to evaluate for each element.  
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray all:^BOOL(id obj) { return [obj intValue] > 0; }]
 *     => true
 *
 *   [myarray all:^BOOL(id obj) { return [obj intValue] < 0; }]
 *     => false
 *   
 *
 * Returns true if, for every object in the array, fn(obj) == true.  If array is empty, returns true.
 */
-(BOOL)all:(BOOL(^)(id obj))fn;

/* Alias for contains. */
-(BOOL)any:(BOOL(^)(id obj))fn;

/* Alias for map. */
-(NSArray*)collect:(id(^)(id obj))fn;

/* Checks to see if at least one object in the array satisfies a condition.
 * 
 * fn - block condition to evaluate for each element.  
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray contains:^BOOL(id obj) { return [obj intValue] > 0; }]
 *     => true
 *
 *   [myarray contains:^BOOL(id obj) { return [obj intValue] == 6; }]
 *     => false
 *
 * Returns true if, for at least one object in the array, fn(obj) == true.  If array is empty, returns false.
 */
-(BOOL)contains:(BOOL(^)(id obj))fn;

/* Counts how many objects in the array satisty the condition.
 * 
 * fn - block condition to evaluate for each element.  
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray count:^BOOL(id obj) { return [obj intValue] > 0; }]
 *     => 5
 *
 *   [myarray count:^BOOL(id obj) { return [obj intValue] < 2; }]
 *     => 1
 *
 * Returns how the number of objects in the array for which fn(obj) == true.  If array is empty, returns 0.
 */
-(NSUInteger)count:(BOOL(^)(id obj))fn;

/* Alias for find. */
-(id)detect:(BOOL(^)(id obj))fn;

-(NSArray*)drop:(NSUInteger)n;

-(void)each:(void(^)(id obj))fn;

-(void)eachWithIndex:(void(^)(id obj, NSUInteger index))fn;

-(BOOL)elementsEqual:(NSArray*)array;

/* Gets a new array with only elements that satisfy a given condition.
 * 
 * fn - block condition to evaluate for each element.  
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray filter:^BOOL(id obj) { return [obj intValue] > 3; }]
 *     => [4, 5]
 *
 *   [myarray filter:^BOOL(id obj) { return [obj intValue] == 6; }]
 *     => []
 *
 * Returns a new array containing every object for which fn(obj) == true.  If array is empty, returns [].
 */
-(NSArray*)filter:(BOOL(^)(id obj))fn;

/* Gets the first element in the array that satisfies a condition.
 * 
 * fn - block condition to evaluate for each element.  
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray find:^BOOL(id obj) { return [obj intValue] > 3; }]
 *     => 4
 *
 *   [myarray find:^BOOL(id obj) { return [obj intValue] == 6; }]
 *     => nil
 *
 * Returns the first element for which fn(obj) == true.  If array is empty or fn(obj) == false for all objects, returns nil.
 */
-(id)find:(BOOL(^)(id obj))fn;

/* Alias for filter. */
-(NSArray*)findAll:(BOOL(^)(id obj))fn;

/* Gets the index of first element in the array that satisfies a condition.
 * 
 * fn - block condition to evaluate for each element.  
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray find:^BOOL(id obj) { return [obj intValue] > 3; }]
 *     => 3
 *
 *   [myarray find:^BOOL(id obj) { return [obj intValue] == 6; }]
 *     => -1
 *
 * Returns the index of the first element for which fn(obj) == true.  If array is empty or fn(obj) == false for all objects, returns -1.
 */
-(NSInteger)findIndex:(BOOL(^)(id obj))fn;
-(id)first;
-(NSArray*)first:(NSUInteger)n;
-(id)foldl:(id) acc fn:(id(^)(id acc, id obj))fn;
-(NSDictionary*)groupBy:(id(^)(id obj))fn;
-(id)inject:(id) acc fn:(id(^)(id acc, id obj))fn;
-(id)last;
-(NSArray*)last:(NSUInteger)n;
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
-(NSArray*)reject:(BOOL(^)(id obj))fn;
-(NSArray*)reverse;
-(NSArray*)select:(BOOL(^)(id obj))fn;
-(NSArray*)sort;
-(NSArray*)sort:(NSComparisonResult(^)(id obj1, id obj2))fn;
-(NSArray*)sortBy:(id(^)(id obj))fn;
-(NSArray*)take:(NSUInteger)n;
-(NSArray*)takeWhile:(BOOL(^)(id obj))fn;
-(NSArray*)unique:(id(^)(id obj))fn;

@end