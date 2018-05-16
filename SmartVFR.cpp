#include <iostream> 
#include <boost/thread/thread.hpp> 
#include <pcl/common/common_headers.h> 
#include <pcl/features/normal_3d.h> 
#include <pcl/io/pcd_io.h> 
#include <pcl/visualization/pcl_visualizer.h> 
#include <pcl/console/parse.h> 
#include <pcl/surface/convex_hull.h> 
#include<pcl/visualization/pcl_plotter.h> 
#include <pcl/visualization/point_picking_event.h>
#include<pcl/io/ply_io.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <QApplication>

#include "mainwindow.h"


void addSphere(float x, float y, float z, boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer, std::string name) {
	pcl::PointXYZRGBA o;
	o.x = x;
	o.y = y;
	o.z = z;
	viewer->addSphere(o, 0.1, name, 0);
}

pcl::PointXYZ Bl;
pcl::PointXYZ Br;
pcl::PointXYZ Bm;
pcl::PointXYZ Dl;
pcl::PointXYZ Dr;
pcl::PointXYZ Dm;
int count;
boost::shared_ptr<pcl::visualization::PCLVisualizer> v;

void initializePoints() {
	/*Bl.x = -2.2075;
	Bl.y = 14.3582;
	Bl.z = 0.67745;
	Br.x = 1.1659;
	Br.y = 14.4407;
	Br.z = -1.50538;
	Bm.x = -0.161;
	Bm.y = 10.8066;
	Bm.z = -0.948497;*/
	//Dl: -14.6477 11.0807 5.26833
	//Dr : -14.6683 11.1601 1.09654
	//Dm : -13.0598 7.32035 3.28745
	Dl.x = -14.6477;
	Dl.y = 11.0807;
	Dl.z = 5.26833;
	Dr.x = -14.6683;
	Dr.y = 11.1601;
	Dr.z = 1.09654;
	Dm.x = -13.0598;
	Dm.y = 7.32035;
	Dm.z = 3.28745;
}

bool clicked; 

void pp_callback(const pcl::visualization::PointPickingEvent& event, void*
	viewer_void) {
	//std::cout << "Picking event active" << std::endl;
	if (event.getPointIndex() != -1)
	{
		//if (count == 0) { event.getPoint(Bl.x, Bl.y, Bl.z); std::cout << "Bl : " << Bl.x << " " << Bl.y << " " << Bl.z << " " << endl; }
		//else if (count == 1) { event.getPoint(Br.x, Br.y, Br.z); std::cout << "Br : " << Br.x << " " << Br.y << " " << Br.z << " " << endl; }
		//else if (count == 2) { event.getPoint(Bm.x, Bm.y, Bm.z); std::cout << "Bm : " << Bm.x << " " << Bm.y << " " << Bm.z << " " << endl; }
		/*
		if (count == 0) { 
			event.getPoint(Dl.x, Dl.y, Dl.z); std::cout << "Dl : " << Dl.x << " " << Dl.y << " " << Dl.z << " " << endl;
			addSphere(Dl.x, Dl.y, Dl.z, v, "Dl");
		}
		else if (count == 1) { 
			event.getPoint(Dr.x, Dr.y, Dr.z); std::cout << "Dr : " << Dr.x << " " << Dr.y << " " << Dr.z << " " << endl;
			addSphere(Dr.x, Dr.y, Dr.z, v, "Dr");
		}
		else if (count == 2) { 
			event.getPoint(Dm.x, Dm.y, Dm.z); std::cout << "Dm : " << Dm.x << " " << Dm.y << " " << Dm.z << " " << endl;
			addSphere(Dm.x, Dm.y, Dm.z, v, "Dm");
		}
		else { click = true; }
		*/
		//float x, y, z;
		//event.getPoint(x, y, z);
		//std::cout << x << ";" << y << ";" << z << std::endl;
		clicked = true;
		count++;
	}
}

boost::shared_ptr<pcl::visualization::PCLVisualizer> customColourVis
(pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud)
{
	// -------------------------------------------- 
	// -----Open 3D viewer and add point cloud----- 
	// -------------------------------------------- 
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new
		pcl::visualization::PCLVisualizer("Virtual Fitting Room"));
	viewer->setBackgroundColor(0.5, 0.5, 0.5);
	viewer->addPointCloud<pcl::PointXYZRGB>(cloud, "sample cloud");
	viewer->setPointCloudRenderingProperties
	(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
	viewer->addCoordinateSystem(1.0);
	viewer->initCameraParameters();
	viewer->registerPointPickingCallback(pp_callback, (void*)&viewer);
	return (viewer);
}


void rotate(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cd, float angle, char axis) {

	float pointx;
	float pointy;
	float pointz;
	if (axis == 'x') {
		for (size_t i = 0; i < cd->size(); i++)
		{
			pointy = cd->points[i].y;
			pointz = cd->points[i].z;
			cd->points[i].y = cos(angle)*pointy - sin(angle)*pointz;
			cd->points[i].z = sin(angle)*pointy + cos(angle)*pointz;
		}
	}
	if (axis == 'y') {
		for (size_t i = 0; i < cd->size(); i++)
		{
			pointx = cd->points[i].x;
			pointz = cd->points[i].z;
			cd->points[i].x = cos(angle)*pointx - sin(angle)*pointz;
			cd->points[i].z = sin(angle)*pointx + cos(angle)*pointz;
		}
	}
	if (axis == 'z') {
		for (size_t i = 0; i < cd->size(); i++)
		{
			pointx = cd->points[i].x;
			pointy = cd->points[i].y;
			cd->points[i].x = cos(angle)*pointx - sin(angle)*pointy;
			cd->points[i].y = sin(angle)*pointx + cos(angle)*pointy;
		}
	}
}

float angle(float x1, float x2, float y1, float y2, float x3, float x4, float y3, float y4) {
	float m1 = (y1 - y2) / (x1 - x2);
	float m2 = (y3 - y4) / (x3 - x4);
	return atan(abs((m2 - m1) / (1 + m2*m1)));
}

float move(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cd, float a, float b, char axis) {
	float t = b - a;
	if (axis == 'x') {
		for (size_t i = 0; i < cd->size(); i++)
		{
			cd->points[i].x += t;
		}
	}
	if (axis == 'y') {
		for (size_t i = 0; i < cd->size(); i++)
		{
			cd->points[i].y += t;
		}
	}
	if (axis == 'z') {
		for (size_t i = 0; i < cd->size(); i++)
		{
			cd->points[i].z += t;
		}
	}
	return t;
}

pcl::PointXYZ rotatePoint(pcl::PointXYZ p, float angle, char axis) {
	float pointx = p.x;
	float pointy = p.y;
	float pointz = p.z;
	if (axis == 'x') {
		p.y = cos(angle)*pointy - sin(angle)*pointz;
		p.z = sin(angle)*pointy + cos(angle)*pointz;
	}
	else if (axis == 'y') {
		p.x = cos(angle)*pointx - sin(angle)*pointz;
		p.z = sin(angle)*pointx + cos(angle)*pointz;
	}
	else if (axis == 'z') {
		p.x = cos(angle)*pointx - sin(angle)*pointy;
		p.y = sin(angle)*pointx + cos(angle)*pointy;
	}
	return p;
}


void align(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr body, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr dress, pcl::PointXYZ Bl, pcl::PointXYZ Br, pcl::PointXYZ Bm, pcl::PointXYZ Dl, pcl::PointXYZ Dr, pcl::PointXYZ Dm) {
	float x1 = move(body, Bl.x, 0.0, 'x') + Br.x;
	float y1 = move(body, Bl.y, 0.0, 'y') + Br.y;
	float z1 = move(body, Bl.z, 0.0, 'z') + Br.z;
	float x3 = move(dress, Dl.x, 0.0, 'x') + Dr.x;
	float y3 = move(dress, Dl.y, 0.0, 'y') + Dr.y;
	float z3 = move(dress, Dl.z, 0.0, 'z') + Dr.z;

	rotate(dress, angle(x3, 0, z3, 0, x1, 0, z1, 0), 'y');
	std::cout << "xz angle : " << angle(x1, 0, z1, 0, x3, 0, z3, 0) << endl;
	Dr = rotatePoint(Dr, angle(x1, 0, z1, 0, x3, 0, z3, 0), 'y');
	Dm = rotatePoint(Dm, angle(x1, 0, z1, 0, x3, 0, z3, 0), 'y');

	//rotate(dress, angle(x1, 0, y1, 0, x3, 0, y3, 0), 'z');
	std::cout << "xy angle : " << angle(x1, 0, y1, 0, x3, 0, y3, 0) << endl;
	Dr = rotatePoint(Dr, angle(x1, 0, y1, 0, x3, 0, y3, 0), 'z');
	Dm = rotatePoint(Dm, angle(x1, 0, y1, 0, x3, 0, y3, 0), 'z');

	//rotate(dress, angle(Dm.y, 0, Dm.z, 0, Bm.y, 0, Bm.z, 0), 'x');
	std::cout << "yz angle : " << angle(Dm.y, 0, Dm.z, 0, Bm.y, 0, Bm.z, 0) << endl;

	move(body, x1 - Br.x, 0.0, 'x') + Br.x;
	move(body, y1 - Br.y, 0.0, 'y') + Br.y;
	move(body, z1 - Br.z, 0.0, 'z') + Br.z;
	move(dress, x1 - Br.x, 0.0, 'x') + Dr.x;
	move(dress, y1 - Br.y, 0.0, 'y') + Dr.y;
	move(dress, z1 - Br.z, 0.0, 'z') + Dr.z;
}

pcl::PointCloud<pcl::PointXYZRGB>::Ptr background_init() {

	pcl::PointCloud<pcl::PointXYZ>::Ptr basic_cloud_ptr(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr(new pcl::PointCloud<pcl::PointXYZRGB>);
	std::cout << "Genarating example point clouds.\n\n";
	// We're going to make an ellipse extruded along the z-axis. The colour for
	// the XYZRGB cloud will gradually go from red to green to blue.
	uint8_t r(184), g(191), b(193);
	for (float y(-2.0); y <= 0.2; y += 0.05)
	{
		for (float angle(0.0); angle <= 360.0; angle += 0.1)
		{
			pcl::PointXYZ basic_point;
			basic_point.x = 10 * cosf(pcl::deg2rad(angle));
			basic_point.y = y;
			basic_point.z = 10 * sinf(pcl::deg2rad(angle));
			basic_cloud_ptr->points.push_back(basic_point);

			pcl::PointXYZRGB point;
			point.x = basic_point.x;
			point.y = basic_point.y;
			point.z = basic_point.z;
			uint32_t rgb = (static_cast<uint32_t>(r) << 16 |
				static_cast<uint32_t>(g) << 8 | static_cast<uint32_t>(b));
			point.rgb = *reinterpret_cast<float*>(&rgb);
			point_cloud_ptr->points.push_back(point);
		}
	}
	for (float radius(0.1); radius <= 10.0; radius += 0.1) {
		for (float angle(0.0); angle <= 360.0; angle += 0.1)
		{
			pcl::PointXYZ basic_point;
			basic_point.x = radius * cosf(pcl::deg2rad(angle));
			basic_point.y = 0.2;
			basic_point.z = radius * sinf(pcl::deg2rad(angle));
			basic_cloud_ptr->points.push_back(basic_point);

			pcl::PointXYZRGB point;
			point.x = basic_point.x;
			point.y = basic_point.y;
			point.z = basic_point.z;
			uint32_t rgb = (static_cast<uint32_t>(r) << 16 |
				static_cast<uint32_t>(g) << 8 | static_cast<uint32_t>(b));
			point.rgb = *reinterpret_cast<float*>(&rgb);
			point_cloud_ptr->points.push_back(point);
		}
	}
	r = 100;
	g = 100;
	b = 100;
	for (float radius(0.1); radius <= 30.0; radius += 0.1) {
		for (float angle(0.0); angle <= 360.0; angle += 0.1)
		{
			pcl::PointXYZ basic_point;
			basic_point.x = radius * cosf(pcl::deg2rad(angle));
			basic_point.y = -2;
			basic_point.z = radius * sinf(pcl::deg2rad(angle));
			basic_cloud_ptr->points.push_back(basic_point);

			pcl::PointXYZRGB point;
			point.x = basic_point.x;
			point.y = basic_point.y;
			point.z = basic_point.z;
			uint32_t rgb = (static_cast<uint32_t>(r) << 16 |
				static_cast<uint32_t>(g) << 8 | static_cast<uint32_t>(b));
			point.rgb = *reinterpret_cast<float*>(&rgb);
			point_cloud_ptr->points.push_back(point);
		}
	}
	basic_cloud_ptr->width = (int)basic_cloud_ptr->points.size();
	basic_cloud_ptr->height = 1;
	point_cloud_ptr->width = (int)point_cloud_ptr->points.size();
	point_cloud_ptr->height = 1;
	return point_cloud_ptr;


}







int
main(int argc, char** argv) {
	QApplication app(argc, argv);

	MainWindow mainWindow;
	mainWindow.show();


	count = 0;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr basic_cloud_ptr(new
		pcl::PointCloud<pcl::PointXYZRGBA>);

	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGBA>);
	
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cd(new pcl::PointCloud<pcl::PointXYZRGBA>);
	pcl::io::loadPLYFile("data/sachin4.ply", *cd);
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cd1(new pcl::PointCloud<pcl::PointXYZRGBA>);
	pcl::io::loadPLYFile("data/shirt_green.ply", *cd1);
	

	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
	viewer = customColourVis(background_init());
	viewer->addPointCloud<pcl::PointXYZRGBA>(cd, "body");
	viewer->addPointCloud<pcl::PointXYZRGBA>(cd1, "shirt");
	viewer->setCameraPosition(43,15,40,0,0,0,0);
	v = viewer;





	bool onceRun= false;
	clicked = false;




	while (!viewer->wasStopped())
	{
		viewer->spinOnce(100);
		
		if (!onceRun) {
			float min = 100000;
			float max = -100000;
			for (size_t i = 0; i < cd->size(); i++)
			{
				if (cd->points[i].y < min) { min = cd->points[i].y; }
				if (cd->points[i].y > max) { max = cd->points[i].y; }
			}
			std::cout << max << endl;
			std::cout << min << endl;
			float height = max - min;
			float armpit = min + height*0.75;
			//addSphere(-13.6, armpit, -2.7, viewer); 
			float shoulder = min + height*0.82;
			float waistline = min + height*0.61;
			std::cout << "shoulder = " << shoulder << endl;
			float xmax = -10000;
			float zmax = -10000;
			float r;
			float rmax = -10000;
			int p;
			int pointcount=0;
			float xsum = 0;
			float zsum = 0;

			for (size_t i = 0; i < cd->size(); i++)
			{
				if (shoulder - 0.1 < cd->points[i].y) {
					if (cd->points[i].y < shoulder + 0.1) {
						pointcount++;
						xsum += cd->points[i].x;
						zsum += cd->points[i].z;
					}
				}
			}
			move(cd, xsum / pointcount, 0.0, 'x');
			move(cd, zsum / pointcount, 0.0, 'z');
			viewer->removePointCloud("body");
			viewer->addPointCloud<pcl::PointXYZRGBA>(cd, "body");

			for (size_t i = 0; i < cd->size(); i++)
			{
				if (shoulder - 0.1 < cd->points[i].y) {
					if (cd->points[i].y < shoulder + 0.1) {
						r = sqrt(cd->points[i].x*cd->points[i].x + cd->points[i].z*cd->points[i].z);
						if (r > rmax) {
							rmax = r;
							p = i;
						}
					}
				}
			}

			float dotproduct;
			rmax = -10000;
			int q;
			for (size_t i = 0; i < cd->size(); i++)
			{
				if (waistline - 0.1 < cd->points[i].y) {
					if (cd->points[i].y < waistline + 0.1) {
						dotproduct = cd->points[i].x*cd->points[p].x + cd->points[i].z*cd->points[p].z;
						if (dotproduct < 0.1) {
							if (dotproduct > -0.1) {
								r = sqrt(cd->points[i].x*cd->points[i].x + cd->points[i].z*cd->points[i].z);
								if (r > rmax) {
									rmax = r;
									q = i;
								}
							}
						}
					}
				}
			}
			//addSphere(xsum/pointcount, shoulder, zsum/pointcount, viewer, "mid");

			//
			addSphere(cd->points[q].x, cd->points[q].y, cd->points[q].z, viewer, "3");
			addSphere(cd->points[p].x, cd->points[p].y, cd->points[p].z, viewer, "1");
			addSphere(-cd->points[p].x, cd->points[p].y, -cd->points[p].z, viewer, "2");
			Bl.x = -cd->points[p].x;
			Bl.y = cd->points[p].y;
			Bl.z = -cd->points[p].z;
			Br.x = cd->points[p].x;
			Br.y = cd->points[p].y;
			Br.z = cd->points[p].z;
			Bm.x = cd->points[q].x;
			Bm.y = cd->points[q].y;
			Bm.z = cd->points[q].z;
			//std::cout << "point" << xmax << ", " << shoulder << ", " << zmax << std::endl;
			//viewer->addPointCloud<pcl::PointXYZRGBA>(cd1, "shirt");
			//viewer->removePointCloud("sample cloud");
			//rotate(cd, 0.52);
			//rotate(cd, 1.571);
			/*for (size_t i = 0; i < cd->size(); i++)
			{
				cd->points[i].x += 100;
			}*/

			//viewer->updatePointCloud(cd, "sample cloud");
			//viewer->addPointCloud<pcl::PointXYZRGBA>(cd, "sample cloud");
			//std::cout << "updated";
			clicked = false;
		}
		if (clicked) {
			initializePoints();
			align(cd, cd1, Bl, Br, Bm, Dl, Dr, Dm);
			viewer->removePointCloud("body");
			viewer->addPointCloud<pcl::PointXYZRGBA>(cd, "body");
			viewer->removePointCloud("shirt");
			viewer->addPointCloud<pcl::PointXYZRGBA>(cd1, "shirt");
			clicked = false;
		}
			
		onceRun = true;
		boost::this_thread::sleep(boost::posix_time::microseconds(100000));
	}




	return app.exec();
}