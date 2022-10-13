#include "SharedFunctions.h"
#include <memory>
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

int SharedFunctions::GetRandomNumber(int aMin, int aMax)
{
	static std::random_device seed;
	static std::mt19937 rndEngine(seed());
	std::uniform_int_distribution<int> rndDist(aMin, aMax);
	return rndDist(rndEngine);
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

void SharedFunctions::EnemyAsciiTow()
{
	std::cout << R"(
  ,^.					,^.
  |||					|||
  |||       _T_				|||       _T_
  |||   .-.[:|:].-.			|||   .-.[:|:].-.
  ===_ /\|  "'"  |/			===_ /\|  "'"  |/
   E]_|\/ \--|-|''''|			 E]_|\/ \--|-|''''|
   O  `'  '=[:]| A  |			 O  `'  '=[:]| A  |
          /""""|  P |			        /""""|  P |
         /"""""`.__.'			       /"""""`.__.'
        []"/"""\"[]			      []"/"""\"[]
        | \     / |			      | \     / |
        | |     | |			      | |     | |
      <\\\)     (///>		            <\\\)     (///>
)";

}

void SharedFunctions::EnemyAsciiThree()
{
	std::cout << R"(
  ,^.					,^.                                 ,^.
  |||					|||                                 |||
  |||       _T_				|||       _T_                       |||       _T_
  |||   .-.[:|:].-.			|||   .-.[:|:].-.                   |||   .-.[:|:].-.
  ===_ /\|  "'"  |/			===_ /\|  "'"  |/                   ===_ /\|  "'"  |/
   E]_|\/ \--|-|''''|			 E]_|\/ \--|-|''''|                  E]_|\/ \--|-|''''|
   O  `'  '=[:]| A  |			 O  `'  '=[:]| A  |                  O  `'  '=[:]| A  |
          /""""|  P |			        /""""|  P |                         /""""|  P |
         /"""""`.__.'			       /"""""`.__.'                        /"""""`.__.'
        []"/"""\"[]			      []"/"""\"[]                         []"/"""\"[]  
        | \     / |			      | \     / |                         | \     / |
        | |     | |			      | |     | |	                  | |     | |
      <\\\)     (///>		            <\\\)     (///>                     <\\\)     (///>
)";

}

void SharedFunctions::DrawThisString(std::string art, int nrOfTime)
{
	for (int i = 0; i < nrOfTime; i++)
	{
		std::cout << art << " ";
	}
	std::cout << std::endl;
}

void SharedFunctions::DrawWelcomeAscii()
{

	std::cout << "Welcome to Diablo Game" << std::endl;
	std::cout <<
		R"(
 __     __     ______     __         ______     ______     __    __     ______    
/\ \  _ \ \   /\  ___\   /\ \       /\  ___\   /\  __ \   /\ "-./  \   /\  ___\   
\ \ \/ ".\ \  \ \  __\   \ \ \____  \ \ \____  \ \ \/\ \  \ \ \-./\ \  \ \  __\   
 \ \__/".~\_\  \ \_____\  \ \_____\  \ \_____\  \ \_____\  \ \_\ \ \_\  \ \_____\ 
  \/_/   \/_/   \/_____/   \/_____/   \/_____/   \/_____/   \/_/  \/_/   \/_____/ 
                                                                                  
 )";
	std::cout << R"(
 ___  _       _    _      
| . \<_> ___ | |_ | | ___ 
| | || |<_> || . \| |/ . \
|___/|_|<___||___/|_|\___/
                          )";

	std::cout << std::endl;
	SharedFunctions::DrawLine();
	std::cout << "Info:" << std::endl;
	std::cout << "You win if you can reach room 6" << std::endl;

	std::cout << "Magic Spill will expire after killing 3 enemies" << std::endl;
	system("pause");

}



