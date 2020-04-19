// A Bison parser, made by GNU Bison 3.5.3.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.h"


// Unqualified %code blocks.
#line 31 "parser.y"

#include "ast.h"
#include <iostream>
#include "tinyContext.h"
#include "driver.h"

#undef yylex
#define yylex drv.scanner->yylex

using ccbhj::BiOpt;
using ccbhj::UaOpt;

#line 58 "parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser.y"
namespace ccbhj {
#line 150 "parser.cc"


  /// Build a parser object.
  Parser::Parser (Driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
    , location (std::move (that.location))
  {}
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 27 "parser.y"
{
    yyla.location.begin.filename = yyla.location.end.filename = &drv.output;
}

#line 487 "parser.cc"


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 92 "parser.y"
             {
                (yylhs.value.BLOCK) = new BlockNode();
                (yylhs.value.BLOCK)->statements.push_back((yystack_[0].value.STMT));
            }
#line 617 "parser.cc"
    break;

  case 3:
#line 96 "parser.y"
                    {
                        (yylhs.value.BLOCK)->statements.push_back((yystack_[0].value.STMT));
                    }
#line 625 "parser.cc"
    break;

  case 4:
#line 101 "parser.y"
                { (yylhs.value.STMT) = new ExpStmtNode((yystack_[1].value.EXPR)); }
#line 631 "parser.cc"
    break;

  case 5:
#line 102 "parser.y"
      { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 637 "parser.cc"
    break;

  case 6:
#line 103 "parser.y"
      { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 643 "parser.cc"
    break;

  case 7:
#line 104 "parser.y"
      { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 649 "parser.cc"
    break;

  case 8:
#line 105 "parser.y"
                    { yyerrok; }
#line 655 "parser.cc"
    break;

  case 9:
#line 106 "parser.y"
                    { printf("missing ';'\n"); yyerrok; }
#line 661 "parser.cc"
    break;

  case 10:
#line 109 "parser.y"
                                                          {(yylhs.value.STMT) = new SelectNode((yystack_[2].value.EXPR), (yystack_[0].value.BLOCK)); }
#line 667 "parser.cc"
    break;

  case 11:
#line 110 "parser.y"
                                                     {(yylhs.value.STMT) = new SelectNode((yystack_[4].value.EXPR), (yystack_[2].value.BLOCK), (yystack_[0].value.BLOCK)); }
#line 673 "parser.cc"
    break;

  case 12:
#line 114 "parser.y"
                                          { (yylhs.value.STMT) = new WhileNode((yystack_[3].value.EXPR), (yystack_[1].value.BLOCK)); }
#line 679 "parser.cc"
    break;

  case 13:
#line 115 "parser.y"
                                      { (yylhs.value.STMT) = new WhileNode((yystack_[2].value.EXPR)); }
#line 685 "parser.cc"
    break;

  case 14:
#line 116 "parser.y"
                                                  { (yylhs.value.STMT) = new WhileNode((yystack_[1].value.EXPR), (yystack_[4].value.BLOCK)); }
#line 691 "parser.cc"
    break;

  case 15:
#line 120 "parser.y"
                                                 {
                    (yylhs.value.STMT) = new ForNode(true, new AsgNode((yystack_[7].value.IDENT), (yystack_[5].value.EXPR)), (yystack_[3].value.EXPR), (yystack_[1].value.BLOCK)); }
#line 698 "parser.cc"
    break;

  case 16:
#line 122 "parser.y"
                                                       {
                    (yylhs.value.STMT) = new ForNode(false, new AsgNode((yystack_[7].value.IDENT), (yystack_[5].value.EXPR)), (yystack_[3].value.EXPR), (yystack_[1].value.BLOCK)); }
#line 705 "parser.cc"
    break;

  case 17:
#line 125 "parser.y"
                    {
                        (yylhs.value.EXPR) = new NumNode(std::stoi(*(yystack_[0].value.STR)));
                    }
#line 713 "parser.cc"
    break;

  case 18:
#line 130 "parser.y"
                  { (yylhs.value.IDENT) = new IdentifierNode(*(yystack_[0].value.STR)); }
#line 719 "parser.cc"
    break;

  case 19:
#line 133 "parser.y"
                                    { (yylhs.value.EXPR) = new AsgNode((yystack_[2].value.IDENT), (yystack_[0].value.EXPR)); }
#line 725 "parser.cc"
    break;

  case 20:
#line 134 "parser.y"
      { (yylhs.value.EXPR) = (yystack_[0].value.EXPR); }
#line 731 "parser.cc"
    break;

  case 21:
#line 135 "parser.y"
                                    { (yylhs.value.EXPR) = (yystack_[1].value.EXPR);}
#line 737 "parser.cc"
    break;

  case 22:
#line 136 "parser.y"
                                     { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::plus, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 743 "parser.cc"
    break;

  case 23:
#line 137 "parser.y"
                                    { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::minus, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 749 "parser.cc"
    break;

  case 24:
#line 138 "parser.y"
                                    { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::mul, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 755 "parser.cc"
    break;

  case 25:
#line 139 "parser.y"
                                    { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::div, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 761 "parser.cc"
    break;

  case 26:
#line 140 "parser.y"
                                    { (yylhs.value.EXPR) = new UnaryOperator(UaOpt::neg, (yystack_[0].value.EXPR));}
#line 767 "parser.cc"
    break;

  case 27:
#line 141 "parser.y"
                                    { (yylhs.value.EXPR) = (yystack_[0].value.IDENT);}
#line 773 "parser.cc"
    break;

  case 28:
#line 142 "parser.y"
      { (yylhs.value.EXPR) = (yystack_[0].value.EXPR); }
#line 779 "parser.cc"
    break;

  case 29:
#line 146 "parser.y"
                                     { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::less, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 785 "parser.cc"
    break;

  case 30:
#line 147 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::greater,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 791 "parser.cc"
    break;

  case 31:
#line 148 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::equal,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 797 "parser.cc"
    break;

  case 32:
#line 149 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::nequal,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 803 "parser.cc"
    break;

  case 33:
#line 150 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::eless,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 809 "parser.cc"
    break;

  case 34:
#line 151 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::egreater ,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 815 "parser.cc"
    break;

  case 35:
#line 155 "parser.y"
          { 
        drv.ctx->programBlock = (yystack_[0].value.BLOCK); }
#line 822 "parser.cc"
    break;


#line 826 "parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -11;

  const signed char Parser::yytable_ninf_ = -36;

  const short
  Parser::yypact_[] =
  {
     195,    -1,   -11,   -11,    54,    54,     5,    54,   195,    10,
     155,   -11,   -11,   -11,   -11,   -11,     9,   234,   -11,    15,
     -11,   272,   -11,    54,   282,    -3,   217,    13,   -11,    54,
     -11,   -11,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,   -11,   -11,    20,   163,    84,    54,   282,    -2,
      -2,   -11,   -11,    33,    33,    33,    33,    33,    33,   195,
     -11,   187,    54,    21,     2,   -11,    41,    54,    54,   195,
     -11,   244,   258,    95,   195,   195,   120,   130,   -11,   -11
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,    18,    17,     0,     0,     0,     0,     0,     0,
       0,     2,     5,     6,     7,    28,    27,     0,    20,     0,
       8,     0,    26,     0,     0,    20,     0,     0,     3,     0,
       9,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,    21,    20,     0,     0,     0,    19,    22,
      23,    24,    25,    30,    29,    31,    33,    34,    32,     0,
      13,     0,     0,     0,     0,    12,    20,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,     0,    15,    16
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -11,    -4,   -10,   -11,   -11,   -11,   -11,    11,    45,    -6,
     -11
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19
  };

  const signed char
  Parser::yytable_[] =
  {
      28,    25,   -10,     1,    26,     2,     3,    20,   -10,    34,
      35,    23,   -10,     2,    29,    42,    28,    44,    47,    45,
      27,     6,    69,     7,     8,   -10,     9,    59,     0,   -10,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      25,    61,    32,    33,    34,    35,    67,    68,    70,    21,
      22,    28,    24,     0,    28,    64,    66,     2,     3,     0,
       4,     0,     0,    28,     5,    73,    28,    28,    24,     0,
      76,    77,     0,     0,    48,     0,     0,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     2,     3,     0,
      62,    24,    63,     0,     5,   -11,     1,     0,     2,     3,
       0,   -11,     0,     0,     0,   -11,     0,    21,     0,     0,
       0,     0,    71,    72,     6,   -11,     7,     8,   -11,     9,
       0,     1,   -11,     2,     3,     0,     4,     0,     0,     0,
       5,     1,     0,     2,     3,     0,     4,     0,     0,     6,
       5,     7,     8,     0,     9,     0,     0,    78,     0,     6,
       0,     7,     8,     0,     9,   -35,     1,    79,     2,     3,
       0,     4,     0,     0,     1,     5,     2,     3,     0,     4,
       0,     0,     0,     5,     6,     0,     7,     8,     0,     9,
       0,     0,     6,     0,     7,     8,    60,     9,     1,     0,
       2,     3,     0,     4,     0,     0,     1,     5,     2,     3,
       0,     4,     0,     0,     0,     5,     6,     0,     7,     8,
      65,     9,     0,     0,     6,     0,     7,     8,     1,     9,
       2,     3,     0,     4,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,    30,     6,     0,    46,     8,
       0,     9,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    74,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,    43,
      75,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41
  };

  const signed char
  Parser::yycheck_[] =
  {
      10,     7,     0,     1,     8,     3,     4,     8,     6,    11,
      12,     6,    10,     3,     5,     0,    26,    23,     5,    22,
       9,    19,    20,    21,    22,    23,    24,     7,    -1,    27,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      46,    45,     9,    10,    11,    12,    25,    26,     7,     4,
       5,    61,     7,    -1,    64,    59,    62,     3,     4,    -1,
       6,    -1,    -1,    73,    10,    69,    76,    77,    23,    -1,
      74,    75,    -1,    -1,    29,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     3,     4,    -1,
       6,    46,    47,    -1,    10,     0,     1,    -1,     3,     4,
      -1,     6,    -1,    -1,    -1,    10,    -1,    62,    -1,    -1,
      -1,    -1,    67,    68,    19,    20,    21,    22,    23,    24,
      -1,     1,    27,     3,     4,    -1,     6,    -1,    -1,    -1,
      10,     1,    -1,     3,     4,    -1,     6,    -1,    -1,    19,
      10,    21,    22,    -1,    24,    -1,    -1,    27,    -1,    19,
      -1,    21,    22,    -1,    24,     0,     1,    27,     3,     4,
      -1,     6,    -1,    -1,     1,    10,     3,     4,    -1,     6,
      -1,    -1,    -1,    10,    19,    -1,    21,    22,    -1,    24,
      -1,    -1,    19,    -1,    21,    22,    23,    24,     1,    -1,
       3,     4,    -1,     6,    -1,    -1,     1,    10,     3,     4,
      -1,     6,    -1,    -1,    -1,    10,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    19,    -1,    21,    22,     1,    24,
       3,     4,    -1,     6,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    19,    -1,    21,    22,
      -1,    24,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    22,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,     7,
      22,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     1,     3,     4,     6,    10,    19,    21,    22,    24,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       8,    38,    38,     6,    38,    39,    31,    37,    32,     5,
       1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     7,    39,    22,    21,     5,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,     7,
      23,    31,     6,    38,    31,    23,    39,    25,    26,    20,
       7,    38,    38,    31,    22,    22,    31,    31,    27,    27
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    30,    31,    31,    32,    32,    32,    32,    32,    32,
      33,    33,    34,    34,    34,    35,    35,    36,    37,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    39,
      39,    39,    39,    39,    39,    40
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     1,     1,     1,     2,     2,
       5,     7,     5,     4,     6,     9,     9,     1,     1,     3,
       1,     3,     3,     3,     3,     3,     2,     1,     1,     3,
       3,     3,     3,     3,     3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "IDENTIFIER", "INT_CONST",
  "ASSIGN", "LPAREN", "RPAREN", "SEMI", "PLUS", "MINUS", "MUL", "DIV",
  "GREATER", "LESS", "EQUAL", "ELESS", "EGREATER", "NEQUAL", "IF", "ELSE",
  "WHILE", "DO", "ENDWHILE", "FOR", "TO", "DOWNTO", "ENDDO", "NEG",
  "NO_ELSE", "$accept", "stmts", "stmt", "if_stmt", "while_stmt",
  "for_stmt", "numeric", "ident", "expr", "comparision", "program", YY_NULLPTR
  };


  const unsigned char
  Parser::yyrline_[] =
  {
       0,    92,    92,    96,   101,   102,   103,   104,   105,   106,
     109,   110,   114,   115,   116,   120,   122,   125,   130,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   146,
     147,   148,   149,   150,   151,   155
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
    };
    const int user_token_number_max_ = 284;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 5 "parser.y"
} // ccbhj
#line 1259 "parser.cc"

#line 158 "parser.y"

void ccbhj::Parser::error(const Parser::location_type& l, const std::string& m) {
    drv.error(l, m);
}
