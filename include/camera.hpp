#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "common_include.hpp"
namespace myslam{
    // template <class Scalar_=float>
    class Camera{
        public:
            typedef std::shared_ptr<Camera> Ptr;
            float   fx_, fy_, cx_, cy_, depth_scale_;
            Camera();
            Camera(float fx, float fy, float cx, float cy, float depth_scale=0):
                fx_ ( fx ), fy_ ( fy ), cx_ ( cx ), cy_ ( cy ), depth_scale_ ( depth_scale )
            {}
            ~Camera();

            Vector3d world2camera( const Vector3d& p_w, const SE3<float>& T_c_w );
            Vector3d camera2world( const Vector3d& p_c, const SE3<float>& T_c_w );
            Vector2d camera2pixel( const Vector3d& p_c );
            Vector3d pixel2camera( const Vector2d& p_p, double depth=1 ); 
            Vector3d pixel2world ( const Vector2d& p_p, const SE3<float>& T_c_w, double depth=1 );
            Vector2d world2pixel ( const Vector3d& p_w, const SE3<float>& T_c_w );
    };
}

#endif 