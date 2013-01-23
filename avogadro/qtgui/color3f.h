/******************************************************************************

  This source file is part of the Avogadro project.

  Copyright 2009 Marcus D. Hanwell
  Copyright 2012 Kitware, Inc.

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/

#ifndef AVOGADRO_QTGUI_COLOR3F_H
#define AVOGADRO_QTGUI_COLOR3F_H

namespace Avogadro {
namespace QtGui {

/**
 * @class Color3f color3f.h <avogadro/qtgui/color3f.h>
 * @brief Representation of an RGB color using three floats.
 * @author Marcus D. Hanwell
 *
 * This class represents a color as three floats ranging from 0.0 to 1.0
 * specifying the intensity of the red, green and blue components of the
 * color. It is stored in memory as float[3], and so vectors containing this
 * type may be passed directly to OpenGL and other functions as C arrays.
 *
 * Several convenience functions are provided, the class is written with an
 * emphasis on efficiency and memory layout.
 */

class Color3f
{
public:
  /**
   * Constructor, results in a black Color3f object unless the RGB values are
   * set.
   * @param red Intensity (from 0.0 to 1.0) of the red component of the color.
   * @param green Intensity (from 0.0 to 1.0) of the green component of the color.
   * @param blue Intensity (from 0.0 to 1.0) of the blue component of the color.
   */
  Color3f(float red = 0.0, float green = 0.0, float blue = 0.0);

  /**
   * Constructor where the color is constructed from integer values.
   * @param red Intensity (from 0 to 255) of the red component of the color.
   * @param green Intensity (from 0 to 255) of the green component of the color.
   * @param blue Intensity (from 0 to 255) of the blue component of the color.
   */
  Color3f(int red, int green, int blue);

  /**
   * Sets the color objects components.
   * @param red Intensity (from 0.0 to 1.0) of the red component of the color.
   * @param green Intensity (from 0.0 to 1.0) of the green component of the color.
   * @param blue Intensity (from 0.0 to 1.0) of the blue component of the color.
   */
  void set(float red, float green, float blue);

  /**
   * @return The intensity of the red component of the color (0.0 to 1.0).
   */
  float red() const { return m_data[0]; }

  /**
   * @return The intensity of the green component of the color (0.0 to 1.0).
   */
  float green() const { return m_data[1]; }

  /**
   * @return The intensity of the blue component of the color (0.0 to 1.0).
   */
  float blue() const { return m_data[2]; }

  /**
   * @return Direct access to the underlying float array of size 3.
   */
  float * data();

  /**
   * This function is useful when calling OpenGL functions which expect a
   * float * array of size 3.
   * @return Direct access to the underlying float array of size 3.
   */
  const float * data() const;

protected:
  float m_data[3];
};

inline Color3f::Color3f(float r, float g, float b)
{
  m_data[0] = r;
  m_data[1] = g;
  m_data[2] = b;
}

inline Color3f::Color3f(int r, int g, int b)
{
  m_data[0] = r / 255.0f;
  m_data[1] = g / 255.0f;
  m_data[2] = b / 255.0f;
}

inline void Color3f::set(float r, float g, float b)
{
  m_data[0] = r;
  m_data[1] = g;
  m_data[2] = b;
}

inline float * Color3f::data()
{
  return &(m_data[0]);
}

inline const float * Color3f::data() const
{
  return &(m_data[0]);
}

} // End namespace QtGui
} // End namespace Avogadro

#endif // AVOGADRO_QTGUI_COLOR3F_H