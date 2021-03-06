// Copyright 2012 Mozilla Corporation. All rights reserved.
// This code is governed by the license found in the LICENSE file.

/**
 * @description Tests that Intl.Collator.prototype
 *     meets the requirements for built-in objects defined by the introduction of
 *     chapter 15 of the ECMAScript Language Specification.
 * @author Norbert Lindenberg
 */

$INCLUDE("testBuiltInObject.js");

testBuiltInObject(Intl.Collator.prototype, false, false, ["constructor", "compare", "resolvedOptions"]);

