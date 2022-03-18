#include <iostream>
#include <opencv2/opencv.hpp>
#include <librealsense2/rs.h>

#include "cv-helpers.hpp"

const size_t windwoWidth = 848;
const size_t windowHeight = 800;



using namespace cv;
using namespace rs2;

int main()
{
	rs2::config cfg;
	pipeline pipe;

	cfg.enable_stream(RS2_STREAM_POSE, 848, 800, RS2_FORMAT_Y8, 30);
	auto config = pipe.start(cfg);
	rs2::align align_to(RS2_STREAM_POSE);

	namedWindow("RS-OpenCV-Test", WINDOW_AUTOSIZE);
	
	while (true)
	{
		auto data = pipe.wait_for_frames();
		data = align_to.process(data);

		auto ir_frame = data.get_infrared_frame();

		Mat ir_mat;
		ir_mat = frame_to_mat(ir_frame);

		imshow("RS-OpenCV-Test", ir_mat);

		if (waitKey(1) >= 0)
			break;
	}

	return 0;
}