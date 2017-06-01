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

/**
 The possible kinds of motion curves that can be used to describe an animation.
 */
typedef NS_ENUM(NSUInteger, MDMMotionCurveType) {
  /**
   The value will be instantly set with no animation.
   */
  MDMMotionCurveTypeInstant,

  /**
   The value will be animated using a cubic bezier curve to model its velocity.
   */
  MDMMotionCurveTypeBezier,

  /**
   The value will be animated using a spring simulation.
   */
  MDMMotionCurveTypeSpring,

  /**
   The default curve will be used.
   */
  MDMMotionCurveTypeDefault,

} NS_SWIFT_NAME(MotionCurveType);

/**
 A generalized representation of a motion curve.
 */
struct MDMMotionCurve {
  /**
   The type defines how to interpret the data values.
   */
  MDMMotionCurveType type;

  /**
   The data values corresponding with this curve.
   */
  CGFloat data[4];
} NS_SWIFT_NAME(MotionCurve);
typedef struct MDMMotionCurve MDMMotionCurve;

/**
 Creates a bezier motion curve with the provided control points.

 A cubic bezier has four control points in total. We assume that the first control point is 0, 0 and
 the last control point is 1, 1. This method requires that you provide the second and third control
 points.

 See the documentation for CAMediaTimingFunction for more information.
 */
FOUNDATION_EXTERN MDMMotionCurve MDMMotionCurveMakeBezier(float p1x, float p1y, float p2x, float p2y)
NS_SWIFT_NAME(MotionCurveMakeBezier(p1x:p1y:p2x:p2y:));

/**
 Creates a spring curve with the provided configuration.

 Tension and friction map to Core Animation's stiffness and damping, respectively.

 See the documentation for CASpringAnimation for more information.
 */
FOUNDATION_EXTERN MDMMotionCurve MDMMotionCurveMakeSpring(float mass, float tension, float friction)
NS_SWIFT_NAME(MotionCurveMakeSpring(mass:tension:friction:));

#define _MDMBezier(p1x, p1y, p2x, p2y) (MDMMotionCurve){ \
.type = MDMMotionCurveTypeBezier, \
.data = {p1x, p1y, p2x, p2y} \
}

#define _MDMSpring(mass, tension, friction) (MDMMotionCurve){ \
.type = MDMMotionCurveTypeSpring, \
.data = {mass, tension, friction} \
}

typedef NS_ENUM(NSUInteger, MDMBezierMotionCurveDataIndex) {
  MDMSpringMotionCurveDataIndexP1X,
  MDMSpringMotionCurveDataIndexP1Y,
  MDMSpringMotionCurveDataIndexP2X,
  MDMSpringMotionCurveDataIndexP2Y
} NS_SWIFT_NAME(BezierMotionCurveDataIndex);

typedef NS_ENUM(NSUInteger, MDMSpringMotionCurveDataIndex) {
  MDMSpringMotionCurveDataIndexMass,
  MDMSpringMotionCurveDataIndexTension,
  MDMSpringMotionCurveDataIndexFriction
} NS_SWIFT_NAME(SpringMotionCurveDataIndex);
