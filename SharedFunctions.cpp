#include "SharedFunctions.h"

int SharedFunctions::ReadInputInt()
{
	bool okInput = true;
	int inputNr = 0;

	while (okInput)
	{
		std::cin >> inputNr;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Type an INTEGER!" << std::endl;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			okInput = false;
		}
	}
	return inputNr;
}

int SharedFunctions::ReadInputInt(int aMinNr, int aMaxNr)
{
	bool okInput = true;
	int inputNr = 0;

	while (okInput)
	{
		std::cin >> inputNr;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Type an INTEGER!" << std::endl;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			okInput = false;
		}
		if (!(inputNr >= aMinNr && inputNr <= aMaxNr))
		{
			std::cout << "worng Input!" << std::endl;
			okInput = true;
		}
	}
	return inputNr;
}

void SharedFunctions::DeathAscii()
{
	{
		std::cout << R"(
      %%% %%%%%%%            |#|
    %%%% %%%%%%%%%%%        |#|####
  %%%%% %         %%%       |#|=#####
 %%%%% %   @    @   %%      | | ==####
%%%%%% % (_  ()  )  %%     | |    ===##
%%  %%% %  \_    | %%      | |       =##
%    %%%% %  u^uuu %%     | |         ==#
      %%%% %%%%%%%%%      | |           V
)" << std::endl;
	}

}

void SharedFunctions::DorrAscii()
{
	std::cout << R"(
      ______
   ,-' ;  ! `-.
  / :  !  :  . \
 |_ ;   __:  ;  |
 )| .  :)(.  !  |
 |"    (##)  _  |
 |  :  ;`'  (_) (
 |  :  :  .     |
 )_ !  ,  ;  ;  |
 || .  .  :  :  |
 |" .  |  :  .  |
 |mt-2_;----.___|
)" << std::endl;	
	
}

void SharedFunctions::EnemyAscii()
{
//	std::cout << R"(
//  ,/         \.
// ((           ))
//  \`.       ,'/
//   )')     (`(
// ,'`/       \,`.
//(`-(         )-')
// \-'\,-'"`-./`-/
//  \-')     (`-/
//  /`'       `'\
// (  _       _  )
// | ( \     / ) |
// |  `.\   /,'  |
// |    `\ /'    |
// (             )
//  \           /
//   \         /
//    `.     ,'
//      `-.-'
//)" ;
	std::cout << R"(
  ,^.
  |||
  |||       _T_
  |||   .-.[:|:].-.
  ===_ /\|  "'"  |/
   E]_|\/ \--|-|''''|
   O  `'  '=[:]| A  |
          /""""|  P |
         /"""""`.__.'
        []"/"""\"[]
        | \     / |
        | |     | |
      <\\\)     (///>
)" ;
}

void SharedFunctions::DrawLine()
{
	std::cout << "-------------------------------------" << std::endl;
}
