#ifndef MAPPOINT_HPP
#define MAPPOINT_HPP

#include "common_include.hpp"

namespace myslam{
    
    class Frame;
    class MapPoint{
        public:
            typedef shared_ptr<MapPoint>    Ptr;
            unsigned long                   id_;        // ID
            static unsigned long            factory_id_;    // factory id
            bool                            good_;      // wheter a good point 
            Eigen::Vector3d                 pos_;       // Position in world
            Eigen::Vector3d                 norm_;      // Normal of viewing direction 
            cv::Mat                         descriptor_; // Descriptor for matching 
            list<Frame*>                    observed_frames_;   // key-frames that can observe this point 
            int                             matched_times_;     // being an inliner in pose estimation
            int                             visible_times_;     // being visible in current frame 
            
            MapPoint();
            MapPoint( 
                unsigned long id, 
                const Eigen::Vector3d& position, 
                const Eigen::Vector3d& norm, 
                Frame* frame=nullptr, 
                const cv::Mat& descriptor=cv::Mat() 
            );
            
            inline cv::Point3f getPositionCV() const {
                return cv::Point3f( pos_(0,0), pos_(1,0), pos_(2,0) );
            }
            
            static MapPoint::Ptr createMapPoint();
            static MapPoint::Ptr createMapPoint( 
            const Eigen::Vector3d& pos_world, 
            const Eigen::Vector3d& norm_,
            const cv::Mat& descriptor,
            Frame* frame );
    };
}

#endif // MAPPOINT_H
