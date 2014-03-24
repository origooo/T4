-module(assignment5).

-include_lib("eqc/include/eqc.hrl").

-compile(export_all).

prop_seq3() ->
	?FORALL({From,To,Incr},{int(),int(),int()},
		%collect({From,To,Incr},
			?IMPLIES(((Incr /= 0) and (From /= To)),
				try 
					List = lists:seq(From,To,Incr),
					CorrectIncrement = check_incr(List,Incr),
					length(List) == (To - From + Incr) div Incr andalso CorrectIncrement
				catch
					error:_ ->
						((To < From) and (Incr > 0))
							or
						((To > From) and (Incr < 0))
				end
			) %% ?IMPLIES ends
		%) %% Collect ends
	).

check_incr([],_Incr) ->
	true;
check_incr([X,Xs|Y],Incr) when X+Incr==Xs ->
	check_incr([Xs|Y], Incr);
check_incr([_X|[]],Incr) -> 
	check_incr([], Incr);
check_incr(_List,_Incr) ->
	false.

%%%----------------------------------------------------------------------------
%%% 2. Testing if deleting an existing list element returns the length of the original list minus one. Works for all datatypes possibly generated
%%%----------------------------------------------------------------------------
%%
%%	The following equalities should hold:
%%	If element exists: length(List) - 1 == length(lists:delete(DeleteThis,List))
%%	If element does not exist: List == lists:delete(DeleteThis,List)

prop_list_delete() ->
	?FORALL({List,DeleteThis},
		{getList(),getElement()},
		%collect({List},
				case lists:member(DeleteThis,List) of
					true -> length(List) - 1 == length(lists:delete(DeleteThis,List));
					false -> List == lists:delete(DeleteThis,List)
				end
		%) %% Collect ends
	).

getList() -> 
	oneof([list(int()),list(char()),list(bool()),list(binary()),list(bitstring())]).
getElement() -> 
	oneof([int(),char(),bool(),binary(),bitstring()]).

%%%----------------------------------------------------------------------------
%%% 3. Checking list properties
%%%----------------------------------------------------------------------------
%% Failure:
%%   List is not equal to the original list after adding one element and deleting that element.
%%
%% The following equalities hold for adding and then deleting one element:
%%   List == lists:delete(lists:last(List),lists:append(Num,List))

prop_list_add_delete() ->
	?FORALL({List,Element},
		{list(int()),int()},
		%collect({List,Element},
			?IMPLIES(List /= [],
					List == lists:delete(Element,lists:append([Element],List))
			) %% ?IMPLIES ends
		%) %% Collect ends
	).

%%%----------------------------------------------------------------------------
%%% 4. last_day_of_the_month()
%%%----------------------------------------------------------------------------

prop_day() ->
	?FORALL({Year,Month},
		{year(),month()},
		%collect({Year, Month},
			getDay({Year,Month}) == calendar:last_day_of_the_month(Year,Month)
		%) %% Collect ends
	).

year() -> ?LET(N,int(),abs(N)).
month() -> ?LET(N,int(),abs(N rem 12) + 1).

getDay({Year,Month}) ->
		Leap = case calendar:is_leap_year(Year) of
			true -> 1;
			false -> 0
		end,
		
		case Month of
			2 -> 28 + Leap;
			_ -> 31 - (Month - 1) rem 7 rem 2
		end.

%%%----------------------------------------------------------------------------
%%% 5. Get time and calculate the amount of seconds passed for current day.
%%%	   Compare to calendar:time_to_seconds({Day,Minute,Second}).
%%%----------------------------------------------------------------------------

prop_time_to_seconds() ->
	?FORALL({H,M,S},{hours(),minutes(),seconds()},
		calc_seconds({H,M,S}) == calendar:time_to_seconds({H,M,S})
	).

calc_seconds({H,M,S}) ->
	(H * 60 * 60) + (M * 60) + S.

hours() -> ?LET(X,int(),abs(X) rem 24).
minutes() -> ?LET(X,int(),abs(X) rem 60).
seconds() -> ?LET(X,int(),abs(X) rem 60).

