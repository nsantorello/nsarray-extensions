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

/* Iterates across the elements of the array and applies a function to each of them.
 * 
 * fn - function to apply to each element
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray each:^void(id obj) { NSLog(@"The number is: %@", obj); }]
 *     => The number is: 1
 *        The number is: 2
 *        The number is: 3
 *        The number is: 4
 *        The number is: 5
 *
 * Returns nothing.
 */
-(void)each:(void(^)(id obj))fn;

/* Iterates across the elements of the array and applies a function to each of them.
 * 
 * fn - function to apply to each element
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray each:^void(id obj, NSUInteger index) { NSLog(@"The number at array index %i is: %@", index, obj); }]
 *     => The number at array index 0 is: 1
 *        The number at array index 1 is: 2
 *        The number at array index 2 is: 3
 *        The number at array index 3 is: 4
 *        The number at array index 4 is: 5
 *
 * Returns nothing.
 */
-(void)eachWithIndex:(void(^)(id obj, NSUInteger index))fn;

/* Checks if each element in this array is equal to each element in another array using isEqual: for equality.
 * Additionally, arrays are only equal if they are the same length (e.g. so [1, 2] != [1, 2, 3]).
 * 
 * array - array to test against for equality
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   samearray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   thirdarray = [1, 2, 3] (of type NSNumber)
 *   fourtharray = [] (of type NSNumber)
 *   [myarray elementsEqual:samearray]
 *     => true
 *
 *   [myarray elementsEqual:thirdarray]
 *     => false
 * 
 *   [myarray elementsEqual:fourtharray]
 *     => false
 *
 * Returns true if each element in another array is equal to the element in this array at the same 
 * index (using isEqual: for equality) and both arrays are the same length; false otherwise.
 */
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
-(id)fold:(id)acc fn:(id(^)(id acc, id obj))fn;

/* Groups elements in the array based on the return value of a function applied to each element.
 * 
 * fn - condition to evaluate for each element; MUST return an NSObject (or subclass)
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray groupBy:^id(id obj) { return [NSNumber numberWithInt:([obj intValue] % 2)]; }]
 *     => {
 *           0 => [2, 4]
 *           1 => [1, 3, 5]
 *        }
 *   
 *   myarray = ["apple", "aardvark", "box", "cat", "carton", "dog", "dj", "dig"];
 *   [myarray groupBy:^id(id obj) { return [NSString stringWithCharacters:[obj characterAtIndex:0] length:1]; }] // Base uniqueness on first character of each string
 *     => {
 *           "a" => ["apple", "aardvark"]
 *           "b" => ["box"]
 *           "c" => ["cat", "carton"]
 *           "d" => ["dog", "dj", "dig"]
 *        }
 *
 *   [myarray groupBy:^id(id obj) { return [NSNumber numberWithInt:[obj length]]; }] // Base uniqueness on length of each string
 *     => {
 *           2 => ["dj"]
 *           3 => ["box", "cat", "dog", "dig"]
 *           5 => ["apple"]
 *           6 => ["carton"]
 *           8 => ["aardvark"];
 *        }
 *
 * Returns a dictionary with keys = fn(obj) and values = obj.  If array is empty, returns {} (an empty dictionary).
 */
-(NSDictionary*)groupBy:(id(^)(id obj))fn;

/* Alias for reduce. */
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

/* Creates a new array with the results of applying a function once for every element.
 * 
 * fn - function to apply to each element
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray map:^id(id obj) { return [NSNumber numberWithInt:([obj intValue] % 2)]; }]
 *     => [0, 1, 0, 1, 0]
 *   
 *   myarray = ["apple", "aardvark", "box", "cat", "carton", "dog", "dj", "dig"];
 *   [myarray map:^id(id obj) { return [NSString stringWithCharacters:[obj characterAtIndex:0] length:1]; }]
 *     => ["a", "a", "b", "c", "c", "d", "d", "d"]
 *
 *   [myarray map:^id(id obj) { return [NSNumber numberWithInt:[obj length]]; }]
 *     => [5, 8, 3, 3, 6, 3, 2, 3]
 *
 * Returns an array with each element being fn(obj) of the corresponding element in the original array.  If array is empty, returns [].
 */
-(NSArray*)map:(id(^)(id obj))fn;

/* Gets the max element in the array as determined by each object's compare: implementation.
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray max]
 *     => 5
 *
 * Returns the max element in the array.  If the array is empty, returns nil.
 */
-(id)max;

/* Gets the max element as determined by a block.
 *
 * fn - comparison to evaluate
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray max:^NSComparisonResult(id obj1, id obj2) { return [obj1 compare:obj2]; }]
 *     => 5
 *
 * Returns the max element in the array as determined by fn.  If the array is empty, returns nil.
 */
-(id)max:(NSComparisonResult(^)(id obj1, id obj2))fn;

/* Gets the max element of the array based on the value of a function applied to each element.
 *
 * fn - condition to evaluate for each element; MUST return an NSObject (or subclass)
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray maxBy:^id(id obj) { return obj; }] // Base max on compare: as implemented by obj's type
 *     => 5
 *   
 *   myarray = ["boat", "dog", "apple", "carton"];
 *   [myarray maxBy:^id(id obj) { return [NSString stringWithCharacters:[obj characterAtIndex:0] length:1]; }] // Base max on first character of each string
 *     => "dog"
 *
 *   [myarray maxBy:^id(id obj) { return [NSNumber numberWithInt:[obj length]]; }] // Base max on length of each string
 *     => "carton"
 *
 * Returns the max element in the array.  If array is empty, returns nil.
 */
-(id)maxBy:(id(^)(id obj))fn;

/* Gets the min element in the array as determined by each object's compare: implementation.
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray min]
 *     => 1
 *
 * Returns the min element in the array.  If the array is empty, returns nil.
 */
-(id)min;

/* Gets the min element as determined by a block.
 *
 * fn - comparison to evaluate
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray min:^NSComparisonResult(id obj1, id obj2) { return [obj1 compare:obj2]; }]
 *     => 1
 *
 * Returns the min element in the array as determined by fn.  If the array is empty, returns nil.
 */
-(id)min:(NSComparisonResult(^)(id obj1, id obj2))fn;

/* Gets the min element of the array based on the value of a function applied to each element.
 *
 * fn - condition to evaluate for each element; MUST return an NSObject (or subclass)
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray minBy:^id(id obj) { return obj; }] // Base min on compare: as implemented by obj's type
 *     => 1
 *   
 *   myarray = ["boat", "dog", "apple", "carton"];
 *   [myarray minBy:^id(id obj) { return [NSString stringWithCharacters:[obj characterAtIndex:0] length:1]; }] // Base min on first character of each string
 *     => "apple"
 *
 *   [myarray minBy:^id(id obj) { return [NSNumber numberWithInt:[obj length]]; }] // Base min on length of each string
 *     => "dog"
 *
 * Returns the min element in the array.  If array is empty, returns nil.
 */
-(id)minBy:(id(^)(id obj))fn;

/* Gets both the min and max elements in the array as determined by each object's compare: implementation.
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray minMax]
 *     => [1, 5]
 *
 * Returns a new array containing the min at index 0 and the max at index 1.  If the array is empty, returns [].
 */
-(NSArray*)minMax;

/* Gets both the min and max elements in the array as determined by a function.
 *
 * fn - comparison to evaluate
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray minMax:^NSComparisonResult(id obj1, id obj2) { return [obj1 compare:obj2]; }]
 *     => [1, 5]
 *
 * Returns a new array containing the min at index 0 and the max at index 1.  If the array is empty, returns [].
 */
-(NSArray*)minMax:(NSComparisonResult(^)(id obj1, id obj2))fn;

/* Gets the min and max elements of the array based on the value of a function applied to each element.
 *
 * fn - condition to evaluate for each element; MUST return an NSObject (or subclass)
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray minMaxBy:^id(id obj) { return obj; }] // Base comparison on compare: as implemented by obj's type
 *     => [1, 5]
 *   
 *   myarray = ["boat", "dog", "apple", "carton"];
 *   [myarray minMaxBy:^id(id obj) { return [NSString stringWithCharacters:[obj characterAtIndex:0] length:1]; }] // Base comparison on first character of each string
 *     => ["apple", "dog"]
 *
 *   [myarray minMaxBy:^id(id obj) { return [NSNumber numberWithInt:[obj length]]; }] // Base comparison on length of each string
 *     => ["dog", "carton"]
 *
 * Returns a new array containing the min at index 0 and the max at index 1.  If the array is empty, returns [].
 */
-(NSArray*)minMaxBy:(id(^)(id obj))fn;

/* Checks if none of the objects in the array satisfy a condition.
 * 
 * fn - condition to evaluate for each element
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray none:^BOOL(id obj) { return [obj intValue] == 6; }]
 *     => true
 *
 *   [myarray none:^BOOL(id obj) { return [obj intValue] == 1; }]
 *     => false
 *   
 *
 * Returns true if fn(obj) == true for no objects in the array.  If array is empty, returns true.
 */
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

/* Groups each element in the array into one of two buckets based on whether a function applied it returns true or false.
 * 
 * fn - condition to evaluate for each element
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray partition:^id(id obj) { return [obj intValue] % 2 == 0; }]
 *     => [[1, 3, 5], [2, 4]]
 *   
 *   myarray = ["apple", "aardvark", "box", "cat", "carton", "dog", "dj", "dig"];
 *   [myarray partition:^id(id obj) { return [obj characterAtIndex:0] == 'c'; }]
 *     => [["apple", "aardvark", "box", "dog", "dj", "dig"], ["cat", "carton"]]
 *
 *   [myarray partition:^id(id obj) { return [obj length] == 3; }] // Base uniqueness on length of each string
 *     => [["apple", "aardvark", "carton", "dj"], ["box", "cat", "dog", "dig"]]
 *
 * Returns an array containing two arrays; the array at index 0 contains values for which fn(obj) == false, 
 * and the array at index 1 contains values for which fn(obj) == true.  If array is empty, returns an 
 * array with the inner arrays empty [[], []].
 */
-(NSArray*)partition:(BOOL(^)(id obj))fn;

/* Combines all elements of array by applying a function.
 * For a more in-depth explanation of what this does see: http://en.wikipedia.org/wiki/Reduce_(higher-order_function)
 * 
 * acc - initial accumulator value
 * fn - condition to evaluate for each element, and MUST return an NSObject (or subclass)
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray reduce:[NSNumber numberWithInt:0] fn:^id(id acc, id obj) { return [NSNumber numberWithInt:([obj intValue] + [acc intValue])]; }] 
 *     => 15 
 * 
 *   [myarray reduce:[NSNumber numberWithInt:1] fn:^id(id acc, id obj) { return [NSNumber numberWithInt:([obj intValue] * [acc intValue])]; }] 
 *     => 120 
 *   
 *   myarray = ["apple", "aardvark", "box", "cat", "carton", "dog", "dj", "dig"];
 *   [myarray reduce:[NSNumber numberWithInt:0] fn:^id(id acc, id obj) { return [NSNumber numberWithInt:([obj length] + [acc intValue])]; }]
 *     => 33
 *
 * Returns the reduction result of the array.  If array is empty, returns acc.
 */
-(id)reduce:(id)acc fn:(id(^)(id acc, id obj))fn;

/* Gets a new array with only elements that don't satisfy a given condition.
 * 
 * fn - condition to evaluate for each element.  
 *
 * Examples
 * 
 *   myarray = [1, 2, 3, 4, 5] (of type NSNumber)
 *   [myarray reject:^BOOL(id obj) { return [obj intValue] > 3; }]
 *     => [1, 2, 3]
 *
 *   [myarray reject:^BOOL(id obj) { return [obj intValue] == 6; }]
 *     => [1, 2, 3, 4, 5]
 *
 *   [myarray reject:^BOOL(id obj) { return [obj intValue] > 0; }]
 *     => []
 *
 * Returns a new array containing every object for which fn(obj) == false.  If array is empty, returns [].
 */
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