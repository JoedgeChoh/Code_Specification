/**
 * @file downsampling.hpp
 * @brief 此文件为点云降采样的具体实现方法
 * @author 孙凯信 (sunkaixin@weichai.com)
 * @version 1.0
 * @date 2020-09-18
 * 
 * @copyright Copyright (c) 2020  潍柴动力
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2020-09-18 <td>1.0     <td>孙凯信     <td>函数实现
 * </table>
 */
#include "downsampling.h"

/**
 * @brief 此函数用于点云降采样，根据voxel_size对cloud_in点云进行体素滤波。
 * @tparam PointT           点云模板
 * @param  cloud_in         输入的点云
 * @param  cloud_out        输出的点云
 * @param  voxel_size_x     体素网格的长度
 * @param  voxel_size_y     体素网格的宽度
 * @param  voxel_size_z     体素网格的高度
 */
template <typename PointT>
void downsampling(typename pcl::PointCloud<PointT>::Ptr &cloud_in, typename pcl::PointCloud<PointT>::Ptr &cloud_out, const float voxel_size_x, const float voxel_size_y, const float voxel_size_z)
{
    typename pcl::VoxelGrid<PointT> voxel_grid_filter;
    voxel_grid_filter.setLeafSize(voxel_size_x, voxel_size_y, voxel_size_z);
    voxel_grid_filter.setInputCloud(*cloud_in);
    voxel_grid_filter.filter(*cloud_out);
}

