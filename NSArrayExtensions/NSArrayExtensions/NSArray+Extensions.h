#import <Foundation/Foundation.h>

@interface NSArray (Extensions)

/* Checks to see if all objects in the array satisfy a condition.
 * 
 * fn - condition to evaluate for each element.  
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
 * fn - condition to evaluate for each element.  
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
 * fn - condition to evaluate for each element.  
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

/* Drops the first n elements in the array.
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray drop:0]
 *     => [1, 2, 3, 4, 5]
 *
 *   [myarray drop:3]
 *     => [4, 5]
 *
 * Returns a new array without the first n elements in the original array.  If the array is empty, returns [].
 */
-(NSArray*)drop:(NSUInteger)n;

-(void)each:(void(^)(id obj))fn;

-(void)eachWithIndex:(void(^)(id obj, NSUInteger index))fn;

-(BOOL)elementsEqual:(NSArray*)array;

/* Gets a new array with only elements that satisfy a given condition.
 * 
 * fn - condition to evaluate for each element.  
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
 * fn - condition to evaluate for each element. 
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
 * fn - condition to evaluate for each element.  
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray findIndex:^BOOL(id obj) { return [obj intValue] > 3; }]
 *     => 3
 *
 *   [myarray findIndex:^BOOL(id obj) { return [obj intValue] == 6; }]
 *     => -1
 *
 * Returns the index of the first element for which fn(obj) == true.  If array is empty or fn(obj) == false for all objects, returns -1.
 */
-(NSInteger)findIndex:(BOOL(^)(id obj))fn;

/* Gets the first element in the array.
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray first]
 *     => 1
 *
 * Returns the first element in the array.  If the array is empty, returns nil.
 */
-(id)first;

/* Gets the first n elements in the array.
 * 
 * n - number of elements to get
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray first:0]
 *     => []
 *   [myarray first:2]
 *     => [1, 2]
 *   [myarray first:4]
 *     => [1, 2, 3, 4]
 *
 * Returns the first n elements in the array.  If the array is empty, returns [].
 */
-(NSArray*)first:(NSUInteger)n;

/* Alias for reduce. */
-(id)foldl:(id) acc fn:(id(^)(id acc, id obj))fn;

-(NSDictionary*)groupBy:(id(^)(id obj))fn;

-(id)inject:(id) acc fn:(id(^)(id acc, id obj))fn;

/* Gets the last element in the array.
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray last]
 *     => 5
 *
 * Returns the last element in the array.  If the array is empty, returns nil.
 */
-(id)last;

/* Gets the last n elements in the array.
 * 
 * n - number of elements to get
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray last:0]
 *     => []
 *   [myarray last:2]
 *     => [4, 5]
 *   [myarray last:4]
 *     => [2, 3, 4, 5]
 *
 * Returns the last n elements in the array.  If the array is empty, returns [].
 */
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

/* Checks if exactly one object in the array satisfies a condition.
 * 
 * fn - condition to evaluate for each element.  
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray one:^BOOL(id obj) { return [obj intValue] == 2; }]
 *     => true
 *
 *   [myarray one:^BOOL(id obj) { return [obj intValue] > 3; }]
 *     => false
 *   
 *
 * Returns true if fn(obj) == true for exactly one object in the array.  If array is empty, returns false.
 */
-(BOOL)one:(BOOL(^)(id obj))fn;

-(NSArray*)partition:(BOOL(^)(id obj))fn;

-(id)reduce:(id) acc fn:(id(^)(id acc, id obj))fn;

-(NSArray*)reject:(BOOL(^)(id obj))fn;

/* Reverses the order of the elements in the array.
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray reverse]
 *     => [5, 4, 3, 2, 1]
 *
 * Returns a new array with the elements in reverse order of the original.  If array is empty, returns [].
 */
-(NSArray*)reverse;

/* Alias for filter. */
-(NSArray*)select:(BOOL(^)(id obj))fn;

/* Sorts the array using the compare: method of the objects in the array.
 *
 * Examples
 * 
 *   myarray = [2, 4, 1, 5, 3] (of type NSNumber)
 *   [myarray sort]
 *     => [1, 2, 3, 4, 5]
 *
 * Returns a new array with the elements sorted in ascending order according to the object's compare: implementation.  If the array is empty, returns [].
 */
-(NSArray*)sort;

/* Sorts the array using a block.
 *
 * fn - comparison to evaluate
 *
 * Examples
 * 
 *   myarray = [2, 4, 1, 5, 3] (of type NSNumber)
 *   [myarray sort:^NSComparisonResult(id obj1, id obj2) { return [obj1 compare:obj2]; }]
 *     => [1, 2, 3, 4, 5]
 *
 * Returns a new array with the elements sorted in ascending order according to fn(obj1, obj2).  If the array is empty, returns [].
 */
-(NSArray*)sort:(NSComparisonResult(^)(id obj1, id obj2))fn;

/* Sorts the array based on the value of a function applied to each element.
 *
 * fn - condition to evaluate for each element; MUST return an NSObject (or subclass)
 *
 * Examples
 * 
 *   myarray = [2, 4, 1, 5, 3] (of type NSNumber)
 *   [myarray sortBy:^id(id obj) { return obj; }] // Base sort order on compare: as implemented by obj's type
 *     => [1, 2, 3, 4, 5]
 *   
 *   myarray = ["boat", "dog", "apple", "carton"];
 *   [myarray sortBy:^id(id obj) { return [NSString stringWithCharacters:[obj characterAtIndex:0] length:1]; }] // Base sort order on first character of each string
 *     => ["apple", "boat", "carton", "dog"]
 *
 *   [myarray sortBy:^id(id obj) { return [NSNumber numberWithInt:[obj length]]; }] // Base sort order on length of each string
 *     => ["dog", "boat", "apple", "carton"]
 *
 * Returns a new array with elements sorted by the value returned from fn(obj).  If array is empty, returns [].
 */
-(NSArray*)sortBy:(id(^)(id obj))fn;

/* Alias for first: */
-(NSArray*)take:(NSUInteger)n;

/* Evaluates a function for each element of the array until the function returns false.  Then returns all prior elements.
 * 
 * fn - condition to evaluate for each element
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray takeWhile:^BOOL(id obj) { return [obj intValue] == 6; }]
 *     => []
 *
 *   [myarray takeWhile:^BOOL(id obj) { return [obj intValue] != 4; }]
 *     => [1, 2, 3]
 *
 *   [myarray takeWhile:^BOOL(id obj) { return [obj intValue] > 0; }]
 *     => [1, 2, 3, 4, 5]
 *   
 *
 * Returns a new array containing the elements for which fn(obj) == true before the first time that fn(obj) == false.  If array is empty, returns [].
 */
-(NSArray*)takeWhile:(BOOL(^)(id obj))fn;

/* Gets an array without duplicates based on the value of a function applied to each element.
 * The fn parameter allows you to select what value you want to target when looking for 
 * duplication. (e.g. instead of just comparing elements with isEqual)
 * 
 * fn - condition to evaluate for each element, and MUST return an NSObject (or subclass)
 *
 * Examples
 * 
 *   myarray = [1, 1, 1, 2, 2, 3, 4, 4, 5, 5, 5] (of type NSNumber)
 *   [myarray unique:^id(id obj) { return obj; }] // Base uniqueness on isEqual as implemented by obj's type
 *     => [1, 2, 3, 4, 5]
 *   
 *   myarray = ["apple", "aardvark", "box", "cat", "carton", "dog", "dj", "dig"];
 *   [myarray unique:^id(id obj) { return [NSString stringWithCharacters:[obj characterAtIndex:0] length:1]; }] // Base uniqueness on first character of each string
 *     => ["apple", "box", "cat", "dog"]
 *
 *   [myarray unique:^id(id obj) { return [NSNumber numberWithInt:[obj length]]; }] // Base uniqueness on length of each string
 *     => ["apple", "aardvark", "box", "carton", "dj"]
 *
 * Returns a new array without duplicates, where duplicity is based on fn(obj).  If array is empty, returns [].
 */
-(NSArray*)unique:(id(^)(id obj))fn;

@end