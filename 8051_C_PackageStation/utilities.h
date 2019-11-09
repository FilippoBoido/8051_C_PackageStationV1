bit fTrig(bit target)
{
		static bit mem;
		if(target == false && mem == false)
		{
			mem = true;
			return true;
		}
		else if(target == false && mem == true)
		{
			return false;
		}
		else
		{
			mem = false;
			return false;
		}	
}

bit rTrig(bit target)
{
		static bit mem;
		if(target == true && mem == false)
		{
			mem = true;
			return true;
		}
		else if(target == true && mem == true)
		{
			return false;
		}
		else
		{
			mem = false;
			return false;
		}		
}