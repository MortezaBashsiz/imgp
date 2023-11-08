#ifndef GENERAL_HPP
#define GENERAL_HPP


static void help(char** argv)
{
		cout<<"Usage:\n"
				<<  argv[0] << "\n"
				<<  " [--width]\n"
						" [--height]\n"
						" [--camera]\n\n"
						"example:\n"
				<<	argv[0]
				<<	" --width=640 --height=480 --camera=0 \n";
}

#endif // define GENERAL_HPP