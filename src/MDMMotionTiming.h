/*
 Copyright 2017-present the Material Components for iOS authors. All Rights Reserved.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

#import "MDMMotionCurve.h"

/**
 A representation of timing for a simple tween animation.
 */
struct MDMMotionTiming {
  /**
   The amount of time, in seconds, before this animation's value interpolation should begin.
   */
  CFTimeInterval delay;

  /**
   The amount of time, in seconds, over which this animation should interpolate between its values.
   */
  CFTimeInterval duration;

  MDMMotionCurve curve;
} NS_SWIFT_NAME(MotionTiming);
typedef struct MDMMotionTiming MDMMotionTiming;
